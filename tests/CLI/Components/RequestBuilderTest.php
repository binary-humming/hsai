<?hh

namespace Tests\CLI\Components;

use HSAI\CLI\Components\RequestBuilder;
use HSAI\CLI\Request;
use HSAI\Environment;

class RequestTest extends \PHPUnit_Framework_TestCase
{
	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\CLI\Components\RequestBuilder::parseArguments() must be an instance of array, string given
	 */
	public function testAttemptingToPassOtherThanAnArrayOfArguments()
	{
		$request = new Request();
		$requestBuilder = new RequestBuilder();

		$requestBuilder->parseArguments('', $request);
	}

	public function testParsingStringArguments()
	{
		$requestBuilder = new RequestBuilder();

		// Passing only arguments
		$request = new Request();
		$requestBuilder->parseArguments(array('parameter1', 'parameter2'), $request);

		$this->assertEquals(Set{}, $request->getFlags());
		$this->assertEquals(Map{}, $request->getOptions());
		$this->assertEquals(Set{'parameter1', 'parameter2'}, $request->getArguments());

		// Passing only options
		$request = new Request();
		$requestBuilder->parseArguments(array('--env=prod', '--format=json'), $request);

		$this->assertEquals(Set{}, $request->getFlags());
		$this->assertEquals(Map{'env' => 'prod', 'format' => 'json'}, $request->getOptions());
		$this->assertEquals(Set{}, $request->getArguments());

		// Passing only flags
		$request = new Request();                                 // v- intentionally passing a duplicated flag
		$requestBuilder->parseArguments(array('-xmwX', '-h', '-H', '-h'), $request);

		$this->assertEquals(Set{'x', 'm', 'w', 'h', 'H', 'X'}, $request->getFlags());
		$this->assertEquals(Map{}, $request->getOptions());
		$this->assertEquals(Set{}, $request->getArguments());

		// Passing combined stuff
		$request = new Request();                                 // v- intentionally passing a duplicated flag
		$requestBuilder->parseArguments(array('-xmwX', '-h', '-H', '-h', 'parameter1', 'parameter2', '--env=prod', '--format=json'), $request);

		$this->assertEquals(Set{'x', 'm', 'w', 'h', 'H', 'X'}, $request->getFlags());
		$this->assertEquals(Map{'env' => 'prod', 'format' => 'json'}, $request->getOptions());
		$this->assertEquals(Set{'parameter1', 'parameter2'}, $request->getArguments());
	}

	public function testCreatingAndInvokingTheComponent()
	{
		$request = new Request();

		$environment = new Environment();
		$environment->setRequest($request);

		                                                               // v- intentionally passing a duplicated flag
		$requestBuilder = new RequestBuilder(array('-xmwX', '-h', '-H', '-h', 'parameter1', 'parameter2', '--env=prod', '--format=json'));
		$requestBuilder->invoke($environment);

		$this->assertEquals(Set{'x', 'm', 'w', 'h', 'H', 'X'}, $request->getFlags());
		$this->assertEquals(Map{'env' => 'prod', 'format' => 'json'}, $request->getOptions());
		$this->assertEquals(Set{'parameter1', 'parameter2'}, $request->getArguments());
	}

}