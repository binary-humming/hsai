<?hh //strict

namespace HSAI;

abstract class AbstractApplication implements ApplicationInterface
{

    protected Environment $environment;

    protected ComponentInterface $firstComponent;

    protected ComponentInterface $currentComponent;

    public function initialize(): Application
    {
        return $this;
    }

    public function useComponent(ComponentInterface $component): AbstractApplication
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

    public function run(): void
    {
        $this->firstComponent->invoke($this->environment);
    }

    public function getEnvironment(): Map
    {
        return $this->environment;
    }

}



