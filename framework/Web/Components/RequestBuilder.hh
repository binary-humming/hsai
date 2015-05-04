<?hh // strict

namespace HSAI\Web\Components;

use \HSAI\AbstractComponent;
use \HSAI\EnvironmentInterface;

class RequestBuilder extends AbstractComponent
{

	public function invoke(EnvironmentInterface $environment)
	{
		$request = $environment->getRequest();

		$body = file_get_contents('php://input');

		$headers = Map{};

		foreach (getallheaders() as $header => $value) {
			$headers[$header] = $value;
		}

		$cookies = Map{};

		foreach ($_COOKIE as $cookie => $value) {
			$cookies[$cookie] = $value;
		}

		$request
			->setBody($body)
			->setHeaders($headers)
			->setCookies($cookies)
			->setMethod($_SERVER['REQUEST_METHOD'])
			->setPath(parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH))
			->setProtocol($_SERVER['SERVER_PROTOCOL'])
			->setScheme($this->getScheme())
			->setQuery($_SERVER['QUERY_STRING'])
			;

		$this->next($environment);
	}

	public function getScheme(): string
	{
		if (isset($_SERVER['HTTPS']) &&
			($_SERVER['HTTPS'] == 'on' || $_SERVER['HTTPS'] == 1) ||
			isset($_SERVER['HTTP_X_FORWARDED_PROTO']) &&
			$_SERVER['HTTP_X_FORWARDED_PROTO'] == 'https') {
			return 'https';
		}

		return 'http';
	}
	
}