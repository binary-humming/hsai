<?hh //strict

namespace HSAI\CLI;

use \HSAI\AbstractApplication;
use \HSAI\CLI\Components\RequestBuilder;
use \HSAI\Environment;

class Application extends AbstractApplication
{

    public function __construct()
    {
      $request = new Request();
      $response = new Response();
      $response->setContent("Hello World!\n");

      $this->environment = new Environment();
      $this->environment
        ->setRequest($request)
        ->setResponse($response);
    }

	public function useRequestBuilderComponent(array $argv): Application
	{
		$this->useComponent(new RequestBuilder($argv));

		return $this;
	}

	public function getOutPut(): string
	{
		return (string) $this->environment->getResponse();
	}

}

