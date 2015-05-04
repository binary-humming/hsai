<?hh

namespace Tests\WEB;

use HSAI\Web\Application;
use HSAI\Web\Response;

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
		$response->setBody('Hello World!');

		$application = new Application();
		$application->getEnvironment()->setResponse($response);

		$this->assertEquals($response->getBody(), $application->getOutPut());
	}

	public function testApplicationIsAddingTheRequestBuilderToThePipeLine()
	{
		$application = new Application();
		$application->useRequestBuilderComponent(array());

		$this->assertInstanceOf('HSAI\Web\Components\RequestBuilder', $application->getFirstComponent());
	}

	public function testApplicationIsAddingTheResponseBuilderToThePipeLine()
	{
		$application = new Application();
		$application->useResponseBuilderComponent(array());

		$this->assertInstanceOf('HSAI\Web\Components\ResponseBuilder', $application->getFirstComponent());
	}

}