<?hh //strict

namespace WI;

abstract class AbstractApplication implements ApplicationInterface
{

    protected Environment $environment;

    protected AbstractComponent $firstComponent;

    protected AbstractComponent $currentComponent;

    public function initialize(): Application
    {
        return $this;
    }

    public function useComponent(string $componentName): AbstractApplication
    {
	    if (!class_exists($componentName)) {
		    throw new \InvalidArgumentException('The class ['.$componentName.'] can\'t be loaded, please make sure, you have properly setup an auto-loader.');
	    }

        if ($this->firstComponent === null) {
            $this->firstComponent = new $componentName();
            $this->firstComponent->setNext(function() {});
            $this->currentComponent = $this->firstComponent;
        } else {
            $component = new $componentName();
            $env = $this->environment;

            $next = function() use($component, $env) {
                $component->invoke($env);
            };

            $this->currentComponent->setNext($next);

            $this->currentComponent = $component;
            $this->currentComponent->setNext(function() {});
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

