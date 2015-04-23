<?php

namespace Tests;

use HSAI\ServiceInterface;

class CheckAvailableFreeSpaceHelperTest extends \PHPUnit_Framework_TestCase
{
	public function testEnoughAvailableFreeSpace()
	{
		$application = new AbstractApplicationMock();

		$this->assertEquals('', $application->getOutPut());
	}

}

class AbstractApplicationMock implements ServiceInterface
{
	public function getOutPut()
	{
		return '';
	}
}