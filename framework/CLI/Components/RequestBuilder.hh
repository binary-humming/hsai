<?hh // strict

namespace HSAI\CLI\Components;

use \HSAI\AbstractComponent;
use HSAI\CLI\Request;
use \HSAI\EnvironmentInterface;

class RequestBuilder extends AbstractComponent
{

	protected array $argv = array();

	public function __construct(array $argv = array())
	{
		$this->argv = $argv;
	}

	public function invoke(EnvironmentInterface $environment)
	{
		$this->parseArguments($this->argv, $environment->getRequest());

		$this->next($environment);
	}

	/**
	 * Parses the arguments string
	 */
	public function parseArguments(array $arguments, Request $request): void
	{
		for ($i = 0; $i < count($arguments); $i++) {
			$argument = trim($arguments[$i]);

			if (strpos($argument, '--') === 0) {
				$argument = substr($argument, 2);

				$equalSignPosition = strpos($argument, '=');

				if ($equalSignPosition == false) {
					$request->addFlag($argument);
				} else {
					$request->addOption(substr($argument, 0, $equalSignPosition), substr($argument, $equalSignPosition+1));
				}

				continue;
			}

			if (strpos($argument, '-') === 0) {
				$argument = substr($argument, 1);

				$equalSignPosition = strpos($argument, '=');

				if ($equalSignPosition == false) {
					for ($l = 0; $l < strlen($argument); $l++) {
						$request->addFlag($argument[$l]);
					}
				} else {
					$request->addOption(substr($argument, 0, $equalSignPosition), substr($argument, $equalSignPosition+1));
				}

				continue;
			}

			$request->addArgument($argument);
		}
	}

}