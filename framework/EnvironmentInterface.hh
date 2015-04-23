<?hh //strict

namespace HSAI;

interface EnvironmentInterface
{

	public function setRequest(RequestInterface $request): EnvironmentInterface;
  
	public function getRequest(): RequestInterface;
  
	public function setResponse(ResponseInterface $response): EnvironmentInterface;
  
    public function getResponse(): ResponseInterface;

    public function getServices(): Map;

    public function getConfigurations(): Map;

    public function setService(string $name, ServiceInterface $service): EnvironmentInterface;

    public function getService(string $name): ServiceInterface;

    public function setConfiguration(string $name, ConfigurationInterface $configuration): EnvironmentInterface;

    public function getConfiguration(string $name): ConfigurationInterface;
    
}
