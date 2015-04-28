<?hh //strict

namespace HSAI;

/**
 * Class AbstractComponent
 *
 * A component is a piece of code that runs within the pipeline.
 * His responsibilities are to implement the [invoke] method and to make sure the next component runs by executing [next] method.
 *
 * @package HSAI
 */
abstract class AbstractComponent implements ComponentInterface
{

	private ComponentInterface $next;

	/**
	 * Sets the next component in the pipeline to be executed
	 *
	 * @param ComponentInterface $next
	 *
	 * @return $this
	 */
	public function setNext(ComponentInterface $next)
	{
		$this->next = $next;
	}

	/**
	 * Returns the next component to be executed in the pipeline
	 *
	 * @return ComponentInterface|null
	 */
	public function getNext(): ComponentInterface
	{
		return $this->next;
	}

	/**
	 * Calls the next component in the pipeline, if there is one
	 *
	 * @param EnvironmentInterface $environment
	 *
	 * @return null
	 */
	public function next(\HSAI\EnvironmentInterface $environment)
	{
		if ($this->next instanceof ComponentInterface) {
			$this->next->invoke($environment);
		}
	}

}