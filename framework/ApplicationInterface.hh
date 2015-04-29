<?hh //strict

namespace HSAI;

/**
 * Interface ApplicationInterface
 *
 * @package HSAI
 */
interface ApplicationInterface
{

	/**
	 * Runs the application and makes sure to invoke the first component in the pipeline.
	 *
	 * @return $this
	 */
    public function run(): ApplicationInterface;

	/**
	 * Returns the application environment object
	 *
	 * @return EnvironmentInterface|null
	 */
    public function getEnvironment();

	/**
	 * Returns the application generated content
	 *
	 * @return string
	 */
	public function getOutPut(): string;

}
