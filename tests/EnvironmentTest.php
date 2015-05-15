<?hh

namespace Tests;

use HSAI\ConfigurationInterface;
use HSAI\Environment;
use HSAI\RequestInterface;
use HSAI\ResponseInterface;
use HSAI\ServiceInterface;

class EnvironmentTest extends \PHPUnit_Framework_TestCase
{
	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\Environment::setRequest() must implement interface HSAI\RequestInterface, null given
	 */
	public function testSettingAWrongTypeOfRequest()
	{
		$environment = new Environment();
		$environment->setRequest(null);
	}

	public function testSettingAndGettingTheRequestObject()
	{
		$request = new RequestMock();


		$environment = new Environment();
		$environment->setRequest($request);

		$this->assertEquals($request, $environment->getRequest());
	}

	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\Environment::setResponse() must implement interface HSAI\ResponseInterface, null given
	 */
	public function testSettingAWrongTypeOfResponse()
	{
		$environment = new Environment();
		$environment->setResponse(null);
	}

	public function testSettingAndGettingTheResponseObject()
	{
		$response = new ResponseMock();


		$environment = new Environment();
		$environment->setResponse($response);

		$this->assertEquals($response, $environment->getResponse());
	}

	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\Environment::setService() must be an instance of string, null given
	 */
	public function testSettingAWrongTypeOfServiceWithTheWrongTypeOfName()
	{
		$environment = new Environment();
		$environment->setService(null, null);
	}

	public function testSettingAndGettingServices()
	{
		$service1 = new ServiceMock();
		$service2 = new ServiceMock();
		$service3 = new ServiceMock();

		$environment = new Environment();
		$environment->setService('service', $service1);

		$this->assertEquals($service1, $environment->getService('service'));

		$environment->setService('service', $service2);
		$environment->setService('another_service', $service3);

		$this->assertEquals($service2, $environment->getService('service'));
		$this->assertEquals($service3, $environment->getService('another_service'));

		$expectedMapOfServices = Map{};
		$expectedMapOfServices['service'] = $service2;
		$expectedMapOfServices['another_service'] = $service3;

		$this->assertEquals($expectedMapOfServices, $environment->getServices());
	}

	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 1 passed to HSAI\Environment::setConfiguration() must be an instance of string, null given
	 */
	public function testSettingAWrongTypeOfConfigurationWithTheWrongTypeOfName()
	{
		$environment = new Environment();
		$environment->setConfiguration(null, null);
	}

	/**
	 * @expectedException \PHPUnit_Framework_Error
	 * @expectedExceptionMessage Argument 2 passed to HSAI\Environment::setConfiguration() must implement interface HSAI\ConfigurationInterface, null given
	 */
	public function testSettingAWrongTypeOfConfiguration()
	{
		$environment = new Environment();
		$environment->setConfiguration('configuration', null);
	}

	public function testSettingAndGettingConfigurations()
	{
		$configuration1 = new ConfigurationMock();
		$configuration2 = new ConfigurationMock();
		$configuration3 = new ConfigurationMock();

		$environment = new Environment();
		$environment->setConfiguration('configuration', $configuration1);

		$this->assertEquals($configuration1, $environment->getConfiguration('configuration'));

		$environment->setConfiguration('configuration', $configuration2);
		$environment->setConfiguration('another_configuration', $configuration3);

		$this->assertEquals($configuration2, $environment->getConfiguration('configuration'));
		$this->assertEquals($configuration3, $environment->getConfiguration('another_configuration'));

		$expectedMapOfConfigurations = Map{};
		$expectedMapOfConfigurations['configuration'] = $configuration2;
		$expectedMapOfConfigurations['another_configuration'] = $configuration3;

		$this->assertEquals($expectedMapOfConfigurations, $environment->getConfigurations());
	}

}

class RequestMock implements RequestInterface
{

}

class ResponseMock implements ResponseInterface
{

}

class ServiceMock
{

}

class ConfigurationMock implements ConfigurationInterface
{

}
