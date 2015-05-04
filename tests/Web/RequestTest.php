<?hh

namespace Tests\Web;

use HSAI\Web\Request;

class RequestTest extends \PHPUnit_Framework_TestCase
{

	public function testSettingAndGettingRequestId()
	{
		$request = new Request();

		$id = '1234';

		$request->setId($id);

		$this->assertEquals($id, $request->getId());
	}

	public function testSettingAndGettingRequestBody()
	{
		$request = new Request();

		$bodyContent = 'Hi?';

		$request->setBody($bodyContent);

		$this->assertEquals($bodyContent, $request->getBody());
	}

	public function testSettingAndGettingHeaders()
	{
		$request = new Request();

		$headers = Map{'Content-Length' => '100', 'Content-Type' => 'application/json'};

		$request->setHeaders($headers);

		$this->assertEquals($headers, $request->getHeaders());

		$request->setHeader('Host', 'localhost');

		$headers = Map{'Content-Length' => '100', 'Content-Type' => 'application/json', 'Host' => 'localhost'};
		$this->assertEquals($headers, $request->getHeaders());
		$this->assertEquals('localhost', $request->getHeader('Host'));

		$request->setHeader('Content-Type', 'application/xml');
		$this->assertEquals('application/xml', $request->getHeader('Content-Type'));

		$this->assertEquals('', $request->getHeader('User'));
		$this->assertEquals('DefaultValue', $request->getHeader('USer', 'DefaultValue'));
	}

	public function testSettingAndGettingCookies()
	{
		$request = new Request();

		$cookies = Map{'UserId' => '123', 'UserVisitedPages' => '1,2,4,6'};

		$request->setCookies($cookies);

		$this->assertEquals($cookies, $request->getCookies());

		$request->setCookie('UserPreferredFlavours', 'chocolate');

		$cookies = Map{'UserId' => '123', 'UserVisitedPages' => '1,2,4,6', 'UserPreferredFlavours' => 'chocolate'};
		$this->assertEquals($cookies, $request->getCookies());
		$this->assertEquals('chocolate', $request->getCookie('UserPreferredFlavours'));

		$request->setCookie('UserPreferredFlavours', 'vanilla');
		$this->assertEquals('vanilla', $request->getCookie('UserPreferredFlavours'));

		$this->assertEquals('', $request->getCookie('UserPreferredRestos'));
		$this->assertEquals('DefaultValue', $request->getCookie('UserPreferredRestos', 'DefaultValue'));
	}

	public function testSettingAndGettingMethod()
	{
		$request = new Request();

		$method = 'GET';

		$request->setMethod($method);

		$this->assertEquals($method, $request->getMethod());
	}

	public function testSettingAndGettingPath()
	{
		$request = new Request();

		$path = '/user/profile';

		$request->setPath($path);

		$this->assertEquals($path, $request->getPath());
	}

	public function testSettingAndGettingProcotol()
	{
		$request = new Request();

		$protocol = 'HTTP1.1';

		$request->setProtocol($protocol);

		$this->assertEquals($protocol, $request->getProtocol());
	}

	public function testSettingAndGettingQuery()
	{
		$request = new Request();

		$query = 'param1=value1&param2=value2';

		$request->setQuery($query);

		$this->assertEquals($query, $request->getQuery());
	}

	public function testSettingAndGettingScheme()
	{
		$request = new Request();

		$scheme = 'HTTP';

		$request->setScheme($scheme);

		$this->assertEquals($scheme, $request->getScheme());
	}
}