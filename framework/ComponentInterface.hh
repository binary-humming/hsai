<?hh //strict

namespace HSAI;

interface ComponentInterface
{
	
	/*
		Sets the next component in the pipeline to be executed
	*/
	public function setNext($next);

	/*
		Returns the next component in the pipe line
	*/
	public function getNext();
 
 	/*
		Calls the next component in the pipeline
 	*/
 	public function next(EnvironmentInterface $environment);

 	/*
 		Invoke the logic of the component
 	*/
 	public function invoke(EnvironmentInterface $dictionary);
}
