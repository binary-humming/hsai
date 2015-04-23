<?hh //strict

namespace WI\Web;

use WI\RequestInterface;

class Request implements RequestInterface
{

	// The content of the request body
	protected string $body = '';

	// A map with the requested headers
	protected array $headers;

	// A map with the cookie
	protected array $cookies;

	// A string containing the HTTP request method of the request (e.g., "GET", "POST").
	protected string $method = '';

	//  A string containing the request path. The path MUST be relative to the "root" of the application delegate. See Paths.
	protected string $path = '';

	// A string containing the protocol name and version (e.g. "HTTP/1.0" or "HTTP/1.1").
	protected string $protocol = '';

	// A string containing the query string component of the HTTP request URI, without the leading "?" (e.g., "foo=bar&amp;baz=quux"). The value may be an empty string.
	protected string $query = '';

	// A string containing the URI scheme used for the request (e.g., "http", "https"); see URI Scheme.
	protected string $scheme = '';

	// A unique identifier for the request.
	protected string $id = '';


	public function __construct()
	{
		$this->headers = [];
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

    public function setHeader(string $name, string $value): Request
    {
		$this->headers[$name] = $value;

	    return $this;
    }

    public function setHeaders(array $headers): Request
    {
		$this->headers = $headers;

		return $this;
    }

	/*
		Returns the header value if exist otherwise null
	*/
    public function getHeader(string $name)
	{
		if (isset($this->headers[ $name ])) {
			return $this->headers[ $name ];
		}

		return null;
	}

    public function getHeaders(): array
    {
		return $this->headers;
    }

	public function setCookies(array $cookies): Request
    {
	    $this->cookies = $cookies;

	    return $this;
    }

    public function getCookie(string $cookie)
	{
		if (isset($this->cookies[$cookie])) {
			return $this->cookies[$cookie];
		}

		return null;
	}

    public function getCookies(): array
    {
	    return $this->cookies;
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

    public function setId(string $id): Request
    {
		$this->id = $id;

	    return $this;
    }

    public function getId(): string
    {
		return $this->id;
    }

}
