<?hh

namespace Tests\CLI;

use HSAI\CLI\Response;

class ResponseTest extends \PHPUnit_Framework_TestCase
{

	public function testSettingAndGettingContent()
	{
		$response = new Response();

		$content = 'Response';

		$response->setContent($content);

		$this->assertEquals($content, $response->getContent());
	}

	public function testSettingAndGettingContentObject()
	{
		$object = new \stdClass();
		$object->content = 'content';

		$response = new Response();
		$response->setContentObject($object);

		$this->assertEquals($object, $response->getContentObject());
	}

	public function testCastingTheObjectToString()
	{
		$response = new Response();

		$content = 'Response';

		$response->setContent($content);

		$this->assertEquals($content, $response.'');
	}

}