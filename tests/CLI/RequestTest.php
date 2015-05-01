<?hh

namespace Tests\CLI;

use HSAI\CLI\Request;

class RequestTest extends \PHPUnit_Framework_TestCase
{

	public function testSettingAndGettingRequestId()
	{
		$request = new Request();

		$id = '1234';

		$request->setId($id);

		$this->assertEquals($id, $request->getId());
	}

	public function testSettingAndGettingFlags()
	{
		$flags = Set {'A', 'B', 'b', 'c'};

		$request = new Request();
		$request->setFlags($flags);

		$this->assertEquals($flags, $request->getFlags());
		$this->assertFalse($request->doesFlagExists('X'));

		$request->addFlag('X');

		$this->assertTrue($request->doesFlagExists('X'));
	}

	public function testSettingAndGettingArguments()
	{
		$arguments = Set {'command.php', 'parameter1', 'parameter2'};

		$request = new Request();
		$request->setArguments($arguments);

		$this->assertEquals($arguments, $request->getArguments());
		$this->assertFalse($request->doesArgumentExists('parameter3'));

		$request->addArgument('parameter3');

		$this->assertTrue($request->doesArgumentExists('parameter3'));
	}

	public function testSettingAndGettingOptions()
	{
		$options = Map {'compress' => 'true', 'level' => '10'};

		$request = new Request();
		$request->setOptions($options);

		$this->assertEquals($options, $request->getOptions());
		$this->assertFalse($request->doesOptionExists('algorithm'));

		$request->addOption('algorithm', 'gzip');

		$this->assertTrue($request->doesOptionExists('algorithm'));

		$this->assertEquals('true', $request->getOptionValue('compress'));
		$this->assertEquals('10', $request->getOptionValue('level'));
		$this->assertEquals('gzip', $request->getOptionValue('algorithm'));
	}
}