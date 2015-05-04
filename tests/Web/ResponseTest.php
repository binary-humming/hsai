<?hh

namespace Tests\Web;

use HSAI\Web\Cookie;
use HSAI\Web\Response;

class ResponseTest extends \PHPUnit_Framework_TestCase
{

	public function testSettingAndResponseBody()
	{
		$response = new Response();

		$body = 'Hello World!';

		$response->setBody($body);

		$this->assertEquals($body, $response->getBody());
	}

	public function testSettingAndResponseBodyObject()
	{
		$response = new Response();

		$body = new \stdClass();
		$body->content = 'Hello World!';

		$response->setBodyObject($body);

		$this->assertEquals($body, $response->getBodyObject());
	}

	public function testSettingAndGettingHTTPStatus()
	{
		$response = new Response();
		$response->setStatusCode(200);
		$this->assertEquals(200, $response->getStatusCode());
	}

	public function testSettingAndGettingHeaders()
	{
		$response = new Response();

		$headers = Map{'Content-Length' => '100', 'Content-Type' => 'application/json'};

		$response->setHeaders($headers);

		$this->assertEquals($headers, $response->getHeaders());

		$response->setHeader('Host', 'localhost');

		$headers = Map{'Content-Length' => '100', 'Content-Type' => 'application/json', 'Host' => 'localhost'};
		$this->assertEquals($headers, $response->getHeaders());
		$this->assertEquals('localhost', $response->getHeader('Host'));

		$response->setHeader('Content-Type', 'application/xml');
		$this->assertEquals('application/xml', $response->getHeader('Content-Type'));

		$this->assertEquals('', $response->getHeader('User'));
		$this->assertEquals('DefaultValue', $response->getHeader('USer', 'DefaultValue'));
	}

	public function testSettingAndGettingCookies()
	{
		$response = new Response();

		$cookies = Map{'UserId' => new Cookie('UserId', '123'), 'UserVisitedPages' => new Cookie('UserVisitedPages', '1,2,4,6')};

		$response->setCookies($cookies);

		$this->assertEquals($cookies, $response->getCookies());

		$flavorCookie = new Cookie('UserPreferredFlavours', 'chocolate');
		$response->setCookie($flavorCookie);

		$cookies = Map{'UserId' => new Cookie('UserId', '123'), 'UserVisitedPages' => new Cookie('UserVisitedPages', '1,2,4,6'), 'UserPreferredFlavours' => $flavorCookie};
		$this->assertEquals($cookies, $response->getCookies());
		$this->assertEquals('chocolate', $response->getCookie('UserPreferredFlavours')->getValue());

		$newFlavorCookie = new Cookie('UserPreferredFlavours', 'vanilla');
		$response->setCookie($newFlavorCookie);
		$this->assertEquals('vanilla', $response->getCookie('UserPreferredFlavours')->getValue());

		$this->assertEquals(null, $response->getCookie('UserPreferredRestos'));
	}

	public function testCastingResponseToString()
	{
		$response = new Response();

		$body = 'Hello World!';

		$response->setBody($body);
		$this->assertEquals($body, $response.'');
	}

}