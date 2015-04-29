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

	public function setNext(ComponentInterface $next)
	{
		$this->next = $next;
	}

	public function getNext(): ComponentInterface
	{
		return $this->next;
	}

	public function next(\HSAI\EnvironmentInterface $environment): void
	{
		if ($this->next instanceof ComponentInterface) {
			$this->next->invoke($environment);
		}
	}

}