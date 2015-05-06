<?hh //strict

namespace HSAI\Web;

use HSAI\AbstractApplication;
use HSAI\Environment;

/**
 * Class Application
 *
 * @package HSAI\Web
 */
class Application extends AbstractApplication
{

    public function __construct()
    {
      $request = new Request();
      $response = new Response();

      $this->environment = new Environment();
      $this->environment
        ->setRequest($request)
        ->setResponse($response);
    }

    public function useRequestBuilderComponent(): Application
    {
    	$this->useComponent(new \HSAI\Web\Components\RequestBuilder());

    	return $this;
    }

	public function useResponseBuilderComponent(): Application
    {
	    $this->useComponent(new \HSAI\Web\Components\ResponseBuilder());

	    return $this;
    }

	public function getOutPut(): string
	{
		return (string) $this->environment->getResponse();
	}

}

