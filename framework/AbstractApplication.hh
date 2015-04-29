<?hh //strict

namespace HSAI;

/**
 * Class AbstractApplication
 *
 * @package HSAI
 */
abstract class AbstractApplication implements ApplicationInterface
{

    protected Environment $environment;

    protected ComponentInterface $firstComponent;

    protected ComponentInterface $currentComponent;

	/**
	 * Builds up the application pipeline by adding to it the components
	 *
	 * @param ComponentInterface $component
	 */
    public function useComponent(ComponentInterface $component): ApplicationInterface
    {
	    if ($this->firstComponent === null) {
		    $this->firstComponent = $component;
		    $this->currentComponent = $component;
	    } else {
		    $this->currentComponent->setNext($component);
		    $this->currentComponent = $component;
	    }

        return $this;
    }

    public function run(): ApplicationInterface
    {
	    if (!($this->environment instanceof EnvironmentInterface)) {
		    throw new \InvalidArgumentException('No application environment object has been set up to pass along to the components.');
	    }

	    if ($this->firstComponent instanceof ComponentInterface) {
		    $this->firstComponent->invoke($this->environment);
	    } else {
		    throw new \InvalidArgumentException('Nothing to run, there are no components in the pipeline.');
	    }


	    return $this;
    }

	/**
	 * @return EnvironmentInterface|null
	 */
    public function getEnvironment()
    {
        return $this->environment;
    }

	/**
	 * Returns the first component in the pipeline
	 *
	 * @return ComponentInterface
	 */
	public function getFirstComponent(): ComponentInterface
	{
		return $this->firstComponent;
	}
}



