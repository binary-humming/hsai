<?hh //strict

namespace HSAI\Web;

use HSAI\AbstractApplication;
use HSAI\Environment;

class Application extends AbstractApplication
{

    public function __construct()
    {
      $request = new Request();
      $response = new Response();
      $response->setBody('Hello World!, Time: '.time(),"\n");

      $this->environment = new Environment();
      $this->environment
        ->setRequest($request)
        ->setResponse($response);
    }

    public function useStandardComponents(): Application
    {
        $this
            ->useRequestBuilderComponent()
        ;

        return $this;
    }

    public function useRequestBuilderComponent(): Application
    {
    	$this->useComponent('\\WI\\Components\\Web\\RequestBuilder');

    	return $this;
    }

	public function getOutPut(): string
	{
		return (string) $this->environment->getResponse()->toString();
	}

}

