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
	 */
    public function run(): ApplicationInterface;

	/**
	 * Returns the application environment object
	 */
    public function getEnvironment();

	/**
	 * Returns the application generated content
	 */
	public function getOutPut(): string;

}
