<?hh //strict

namespace HSAI\Web;

use \HSAI\RequestInterface;

class Request implements RequestInterface
{

	protected string $id = '';

	protected string $body = '';

	protected Map<string, string> $headers;

	protected Map<string, string> $cookies;

	protected string $method = '';

	protected string $path = '';

	protected string $protocol = '';

	protected string $query = '';

	protected string $scheme = '';

	public function __construct()
	{
		$this->headers = [];
		$this->cookies = [];
	}

	public function setId(string $id): Request
    {
		$this->id = $id;

	    return $this;
    }

	public function getId(): string
    {
	    return $this->id;
    }

	public function setBody(string $body): Request
	{
		$this->body = $body;

		return $this;
	}

	public function getBody(): string
    {
		return $this->body;
    }

    public function setHeaders(Map<string, string> $headers): Request
    {
		$this->headers = $headers;

		return $this;
    }

	public function getHeaders(): Map<string, string>
    {
	    return $this->headers;
    }

	public function setHeader(string $name, string $value): Request
    {
	    $this->headers[$name] = $value;

	    return $this;
    }

    public function getHeader(string $name, $deafult = '')
	{
		if (isset($this->headers[ $name ])) {
			return $this->headers[ $name ];
		}

		return $deafult;
	}

	public function setCookies(Map<string, string> $cookies): Request
    {
	    $this->cookies = $cookies;

	    return $this;
    }

	public function getCookies(): Map<string, string>
    {
	    return $this->cookies;
    }

	public function setCookie(string $name, string $value): Request
    {
	    $this->cookies[$name] = $value;

	    return $this;
    }

    public function getCookie(string $cookie, $default = '')
	{
		if (isset($this->cookies[$cookie])) {
			return $this->cookies[$cookie];
		}

		return $default;
	}

    public function setMethod(string $method): Request
    {
		$this->method = $method;

	    return $this;
    }

    public function getMethod(): string
    {
		return $this->method;
    }

    public function setPath(string $path): Request
    {
		$this->path = $path;

		return $this;
    }

    public function getPath(): string
    {
		return $this->path;
	}

	public function setProtocol(string $protocol): Request
	{
		$this->protocol = $protocol;

		return $this;
	}

	public function getProtocol(): string
    {
		return $this->protocol;
    }

    public function setQuery(string $query): Request
    {
		$this->query = $query;

	    return $this;
    }

    public function getQuery(): string
    {
		return $this->query;
    }

    public function setScheme(string $scheme): Request
    {
		$this->scheme = $scheme;

	    return $this;
    }

    public function getScheme(): string
    {
		return $this->scheme;
    }

}
