<?hh //strict

namespace HSAI;

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

  public function getRequest(): RequestInterface
  {
    return $this->request;
  }

  public function setResponse(ResponseInterface $response): Environment
  {
    $this->response = $response;

    return $this;
  }

  public function getResponse(): ResponseInterface
  {
    return $this->response;
  }

  public function setService(string $name, ServiceInterface $service): Environment
  {
  	$this->services[$name] = $service;

  	return $this;
  }

  public function getService(string $name): ServiceInterface
  {
  	return $this->services->get($name);
  }

  public function setConfiguration(string $name, ConfigurationInterface $configuration): Environment
  {
  	$this->configurations[$name] = $configuration;

  	return $this;
  }

  public function getConfiguration(string $name): ConfigurationInterface
  {
  	return $this->configurations->get($name);
  }

  public function getServices(): Map
  {
  	return $this->services;
  }

  public function getConfigurations(): Map
  {
  	return $this->configurations;
  }

}
