<?hh //strict

namespace WI\Web;

use WI\AbstractApplication;
use WI\Environment;

class Application extends AbstractApplication
{

    public function __construct()
    {
      $request = new Request();
      $response = new Response();
      $response->setBody('Hello World!, Time: '.time());

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

