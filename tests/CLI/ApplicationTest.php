<?hh

namespace Tests\CLI;

use HSAI\CLI\Application;
use HSAI\CLI\Response;

class ApplicationTest extends \PHPUnit_Framework_TestCase
{

	public function testApplicationIsInitializingTheEnvironmentObject()
	{
		$application = new Application();

		$this->assertInstanceOf('HSAI\Environment', $application->getEnvironment());
		$this->assertInstanceOf('HSAI\RequestInterface', $application->getEnvironment()->getRequest());
		$this->assertInstanceOf('HSAI\ResponseInterface', $application->getEnvironment()->getResponse());
	}

	public function testApplicationIsReturningResponseContentThroughGetOutputMethod()
	{
		$response = new Response();
		$response->setContent('Hello World!');

		$application = new Application();
		$application->getEnvironment()->setResponse($response);

		$this->assertEquals($response->getContent(), $application->getOutPut());
	}

	public function testApplicationIsAddingTheRequestBuilderToThePipeLine()
	{
		$application = new Application();
		$application->useRequestBuilderComponent(array());

		$this->assertInstanceOf('HSAI\CLI\Components\RequestBuilder', $application->getFirstComponent());
	}

}