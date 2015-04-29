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

	/**
	 * @param RequestInterface $request
	 *
	 * @return $this
	 */
	public function setRequest(RequestInterface $request): EnvironmentInterface;

	/**
	 * @return RequestInterface|null
	 */
	public function getRequest(): RequestInterface;

	/**
	 * @param ResponseInterface $response
	 *
	 * @return $this
	 */
	public function setResponse(ResponseInterface $response): EnvironmentInterface;

	/**
	 * @return ResponseInterface
	 */
    public function getResponse(): ResponseInterface;

	/***
	 * @param string           $name
	 * @param ServiceInterface $service
	 *
	 * @return $this
	 */
    public function setService(string $name, ServiceInterface $service): EnvironmentInterface;

	/**
	 * @param string $name
	 *
	 * @return ServiceInterface
	 */
    public function getService(string $name): ServiceInterface;

	/**
	 * @return Map<string, ServiceInterface>
	 */
    public function getServices(): Map<string, ServiceInterface>;

	/**
	 * @param string                 $name
	 * @param ConfigurationInterface $configuration
	 *
	 * @return $this
	 */
    public function setConfiguration(string $name, ConfigurationInterface $configuration): EnvironmentInterface;

	/**
	 * @param string $name
	 *
	 * @return ConfigurationInterface
	 */
    public function getConfiguration(string $name): ConfigurationInterface;

	/**
	 * @return Map<string, ConfigurationInterface>
	 */
    public function getConfigurations(): Map<string, ConfigurationInterface>;
    
}
