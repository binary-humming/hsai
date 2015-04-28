<?hh //strict

namespace HSAI;

/**
 * Interface ComponentInterface
 *
 * A component is a piece of code that runs within the pipeline.
 * His responsibilities are to implement the [invoke] method and to make sure the next component runs by executing [next] method.
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
	public function getNext(): ComponentInterface;
 
	/**
	 * Calls the next component in the pipeline
	 *
	 * @param EnvironmentInterface $environment
	 *
	 * @return null
	 */
 	public function next(EnvironmentInterface $environment);

	/**
	 * Executes the logic code of the component, if there is one
	 *
	 * @param EnvironmentInterface $dictionary
	 *
	 * @return null
	 */
 	public function invoke(EnvironmentInterface $dictionary);

}
