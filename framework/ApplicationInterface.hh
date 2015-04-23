<?hh //strict

namespace WI;

interface ApplicationInterface
{

	public function initialize(): ApplicationInterface;

    public function run(): void;

    public function getOutPut(): string;

    public function getEnvironment(): EnvironmentInterface;

}
