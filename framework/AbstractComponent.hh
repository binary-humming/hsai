<?hh //strict

namespace HSAI;

abstract class AbstractComponent implements ComponentInterface
{

	private $next;

	/*
		Sets the next component in the pipeline to be executed
	*/
	public function setNext($next)
	{
		$this->next = $next;
	}

	/*
		Returns the next component in the pipeline
	*/
	public function getNext()
	{
		return $this->next;
	}

	/*
		Calls the next component in the pipeline
 	*/
	public function next(\WI\EnvironmentInterface $environment)
	{
		$next = $this->next;

        $next($environment);
	}

}