<?hh //strict

namespace HSAI;

interface ApplicationInterface
{

	public function initialize(): ApplicationInterface;

    public function run(): void;

    public function getOutPut(): string;

    public function getEnvironment(): EnvironmentInterface;

}
