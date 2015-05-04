<?hh

namespace Tests\Web;

use HSAI\Web\Cookie;

class CookieTest extends \PHPUnit_Framework_TestCase
{

	public function testCallingBasicConstructor()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals('cookie', $cookie->getName());
		$this->assertEquals('chocolate', $cookie->getValue());
	}

	public function testCallingFullConstructor()
	{
		$cookie = new Cookie('cookie', 'chocolate', 123, '/flavours', 'localhost', true, true);

		$this->assertEquals('cookie', $cookie->getName());
		$this->assertEquals('chocolate', $cookie->getValue());
		$this->assertEquals('/flavours', $cookie->getPath());
		$this->assertEquals('localhost', $cookie->getDomain());
		$this->assertEquals(true, $cookie->isSecure());
		$this->assertEquals(true, $cookie->isHttpOnly());
	}

	public function testSettingAndGettingValue()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals('chocolate', $cookie->getValue());

		$cookie->setValue('vanilla');

		$this->assertEquals('vanilla', $cookie->getValue());
	}

	public function testSettingAndGettingExpire()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals(0, $cookie->getExpire());

		$cookie->setExpire(456);
		$this->assertEquals(456, $cookie->getExpire());
	}

	public function testSettingAndGettingPath()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals('/', $cookie->getPath());

		$cookie->setPath('/flavours');
		$this->assertEquals('/flavours', $cookie->getPath());
	}

	public function testSettingAndGettingDomain()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals('', $cookie->getDomain());

		$cookie->setDomain('localhost');
		$this->assertEquals('localhost', $cookie->getDomain());
	}

	public function testSettingAndGettingSecure()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals(false, $cookie->isSecure());

		$cookie->setSecure();
		$this->assertTrue($cookie->isSecure());
		$cookie->setSecure(true);
		$this->assertTrue($cookie->isSecure());
		$cookie->setSecure(false);
		$this->assertTrue(!$cookie->isSecure());
	}

	public function testSettingAndGettingHttpOnly()
	{
		$cookie = new Cookie('cookie', 'chocolate');

		$this->assertEquals(false, $cookie->isHttpOnly());

		$cookie->setHttpOnly();
		$this->assertTrue($cookie->isHttpOnly());
		$cookie->setHttpOnly(true);
		$this->assertTrue($cookie->isHttpOnly());
		$cookie->setHttpOnly(false);
		$this->assertTrue(!$cookie->isHttpOnly());
	}

}