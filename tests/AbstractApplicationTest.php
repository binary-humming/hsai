<?hh

namespace Tests;

use HSAI\AbstractApplication;
use HSAI\Environment;

class AbstractApplicationTest extends \PHPUnit_Framework_TestCase
{

	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\AbstractApplication::useComponent() must implement interface HSAI\ComponentInterface, null given
	 */
	public function testAddingAComponentThatIsNotAnInstanceOfComponentInterface()
	{
		$application = new AbstractApplicationMock();
		$application->useComponent(null);
	}

	public function testAddingTheFirstComponentInThePipeLin()
	{
		$component1 = new AbstractComponentMock();

		$application = new AbstractApplicationMock();
		$application->useComponent($component1);

		$this->assertEquals($component1, $application->getFirstComponent());
	}

	public function testAddingMoreThanOneComponentAndMakingSureThePipelineIsBuild()
	{
		$component1 = new AbstractComponentMock();
		$component2 = new AbstractComponentMock();
		$component3 = new AbstractComponentMock();

		$application = new AbstractApplicationMock();
		$application
			->useComponent($component1)
			->useComponent($component2)
			->useComponent($component3);

		$this->assertEquals($component1, $application->getFirstComponent());
		$this->assertEquals($component2, $component1->getNext());
		$this->assertEquals($component3, $component2->getNext());
		$this->assertNull($component3->getNext());
	}

	public function testGettingTheApplicationEnvironment()
	{
		$application = new AbstractApplicationMock();

		$this->assertNull($application->getEnvironment());
	}

	/**
	 * @expectedException \InvalidArgumentException
	 * @expectedExceptionMessage No application environment object has been set up to pass along to the components.
	 */
	public function testRunningTheApplicationWithoutSettingUpTheEnvironment()
	{
		$application = new AbstractApplicationMock();
		$application->run();
	}

	/**
	 * @expectedException \InvalidArgumentException
	 * @expectedExceptionMessage Nothing to run, there are no components in the pipeline.
	 */
	public function testRunningTheApplicationWithoutComponents()
	{
		$application = new AbstractApplicationWithEnvironmentMock();
		$application->run();
		;
	}

	public function testRunningTheApplication()
	{
		$component1 = new AbstractComponentMock();
		$component2 = new AbstractComponentMock();
		$component3 = new AbstractComponentMock();

		$application = new AbstractApplicationWithEnvironmentMock();
		$application
			->useComponent($component1)
			->useComponent($component2)
			->useComponent($component3)
			->run();
		;

		$this->assertTrue($component1->wasInvoked);
		$this->assertTrue($component2->wasInvoked);
		$this->assertTrue($component3->wasInvoked);
	}
}

class AbstractApplicationMock extends AbstractApplication
{

	public boolean $wasInitialized = false;

	public function initialize(): ApplicationInterface
	{
		$this->wasInitialized = true;

		return parent::initialize();
	}

	public function getOutput(): string
	{
		return '';
	}

}

class AbstractApplicationWithEnvironmentMock extends AbstractApplicationMock
{

	public function __construct()
	{
		$this->environment = new Environment();
	}

}

