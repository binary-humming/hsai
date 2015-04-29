<?hh //strict

namespace HSAI;

/**
 * Interface ComponentInterface
 *
 * A component is a piece of code that runs within the application pipeline.
 * His responsibilities are to implement the [invoke] method and to make sure the next component in the pipeline runs by executing [next] method.
 *
 * @package HSAI
 */
interface ComponentInterface
{
	
	/**
	 * Sets the next component in the pipeline to be executed
	 *
	 * @param ComponentInterface $next
	 *
	 * @return $this
	 */
	public function setNext(ComponentInterface $next): ComponentInterface;

	/**
	 * Returns the next component to be executed in the pipeline
	 *
	 * @return ComponentInterface|null
	 */
	public function getNext();
 
	/**
	 * Calls the next component in the pipeline
	 *
	 * @param EnvironmentInterface $environment
	 */
 	public function next(EnvironmentInterface $environment): void;

	/**
	 * Executes the logic code of the component, if there is one
	 *
	 * @param EnvironmentInterface $environment
	 */
 	public function invoke(EnvironmentInterface $environment): void;

}
