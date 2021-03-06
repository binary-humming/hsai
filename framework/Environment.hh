<?hh //strict

namespace HSAI;

/**
 * Class Environment
 *
 * @package HSAI
 */
class Environment implements EnvironmentInterface
{

	protected Request $request;

	protected Response $response;

	protected Map<string, ServiceInterface> $services;

	protected Map<string, ConfigurationInterface> $configurations;

	public function __construct()
	{
		$this->services = Map{};

  	    $this->configurations = Map{};
    }

	public function setRequest(RequestInterface $request): Environment
    {
        $this->request = $request;

        return $this;
    }

	public function getRequest()
    {
		return $this->request;
    }

    public function setResponse(ResponseInterface $response): Environment
    {
		$this->response = $response;

        return $this;
    }

    public function getResponse()
    {
		return $this->response;
    }

    public function setService(string $name, $service): Environment
    {
		$this->services[$name] = $service;

		return $this;
    }

    public function getService(string $name)
    {
		return $this->services->get($name);
    }

	public function getServices(): Map < string, ServiceInterface >
    {
	    return $this->services;
    }

    public function setConfiguration(string $name, ConfigurationInterface $configuration): Environment
    {
		$this->configurations[ $name ] = $configuration;

        return $this;
    }

    public function getConfiguration(string $name)
    {
		return $this->configurations->get($name);
    }

    public function getConfigurations(): Map < string, ConfigurationInterface >
    {
		return $this->configurations;
    }

}
