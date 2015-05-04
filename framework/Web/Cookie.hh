<?hh

namespace HSAI\Web;

/**
 * Class Cookie
 *
 * @package HSAI\Web
 */
class Cookie
{

	protected string $name;

	protected string $value;

	protected int $expire = 0;

	protected string $path = '/';

	protected string $domain = '';

	protected boolean $secure = false;

	protected boolean $httpOnly = false;

	public function __construct(string $name, string $value, int $expire = 0, string $path = '/', string $domain = '', boolean $secure = false, boolean $httpOnly = false)
	{
		$this
			->setName($name)
			->setValue($value)
			->setExpire($expire)
			->setPath($path)
			->setDomain($domain)
			->setSecure($secure)
			->setHttpOnly($secure)
		;
	}

	protected function setName(string $name): Cookie
	{
		$this->name = $name;

		return $this;
	}

	public function getName(): string
	{
		return $this->name;
	}

	public function setValue(string $value): Cookie
	{
		$this->value = $value;

		return $this;
	}

	public function getValue(): string
	{
		return $this->value;
	}

	public function setExpire(int $expire): Cookie
	{
		$this->expire = $expire;

		return $this;
	}

	public function getExpire(): int
	{
		return $this->expire;
	}

	public function setPath(string $path): Cookie
	{
		$this->path = $path;

		return $this;
	}

	public function getPath(): string
	{
		return $this->path;
	}

	public function setDomain(string $domain): Cookie
	{
		$this->domain = $domain;

		return $this;
	}

	public function getDomain(): string
	{
		return $this->domain;
	}

	public function setSecure(boolean $secure = true): Cookie
	{
		$this->secure = $secure;

		return $this;
	}

	public function isSecure(): boolean
	{
		return $this->secure;
	}

	public function setHttpOnly(boolean $httpOnly = true): Cookie
	{
		$this->httpOnly = $httpOnly;

		return $this;
	}

	public function isHttpOnly(): boolean
	{
		return $this->httpOnly;
	}

}