<?hh

namespace Tests;

use HSAI\Environment;
use HSAI\EnvironmentInterface;
use HSAI\AbstractComponent;

class AbstractComponentTest extends \PHPUnit_Framework_TestCase
{
	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\AbstractComponent::setNext() must implement interface HSAI\ComponentInterface, null given
	 */
	public function testSettingAWrongTypeOfComponent()
	{
		$component1 = new AbstractComponentMock();
		$component1->setNext(null);
	}

	public function testSettingAndGettingNextComponent()
	{
		$component1 = new AbstractComponentMock();
		$component2 = new AbstractComponentMock();

		$component1->setNext($component2);

		$this->assertEquals($component2, $component1->getNext());
	}

	public function testCallingTheInvokeMethodWithNextComponentDefined()
	{
		$environment = new Environment();

		$component1 = new AbstractComponentMock();
		$component2 = new AbstractComponentMock();

		$component1->setNext($component2);

		$component1->invoke($environment);

		$this->assertTrue($component1->wasInvoked);
		$this->assertTrue($component2->wasInvoked);
	}

}

class AbstractComponentMock extends AbstractComponent
{
	public boolean $wasInvoked = false;

	public function invoke(EnvironmentInterface $environment): void
	{
		$this->wasInvoked = true;

		$this->next($environment);
	}
}
