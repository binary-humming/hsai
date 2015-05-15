<?hh //strict

namespace HSAI;

/**
 * Interface EnvironmentInterface
 *
 * An interface to encapsulate the application environment
 *
 * @package HSAI
 */
interface EnvironmentInterface
{

	public function setRequest(RequestInterface $request): EnvironmentInterface;

	public function getRequest();

	public function setResponse(ResponseInterface $response): EnvironmentInterface;

    public function getResponse();

    public function setService(string $name, $service): EnvironmentInterface;

    public function getService(string $name);

    public function getServices(): Map<string, ServiceInterface>;

    public function setConfiguration(string $name, ConfigurationInterface $configuration): EnvironmentInterface;

    public function getConfiguration(string $name);

    public function getConfigurations(): Map<string, ConfigurationInterface>;
    
}
