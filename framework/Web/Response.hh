<?hh //strict

namespace HSAI\Web;

use \HSAI\ResponseInterface;

class Response implements ResponseInterface
{

    protected string $body = '';

	protected \stdClass $bodyObject;

	protected string $statusCode = 200;

	protected string $statusCodeMessage = 'OK';

	protected string $protocolVersion = '1.1'; //TODO: update unit test

    protected Map<string, string> $headers;

	protected Map<string, Cookie> $cookies;

	public function __construct()
	{
		$this->headers = Map{};
		$this->cookies = Map{};
	}

    public function setBody(string $body): Response
    {
        $this->body = $body;

        return $this;
    }

    public function getBody(): string
    {
        return $this->body;
    }

	public function setBodyObject(\stdClass $body): Response
    {
		$this->bodyObject = $body;

		return $this;
	}

    public function getBodyObject()
    {
		return $this->bodyObject;
	}

	public function setStatusCode(int $code, string $message = ''): Response
	{
		$this->statusCode = $code;

		if ($message !== '') {
			$this->setStatusCodeMessage($message);
		}

		return $this;
	}

	public function getStatusCode(): int
	{
		return $this->statusCode;
	}

	public function setStatusCodeMessage(string $codeMessage): Response
	{
		$this->statusCodeMessage = $codeMessage;

		return $this;
	}

	public function getStatusCodeMessage(): string
	{
		return $this->statusCodeMessage;
	}

	public function setHeaders(Map<string, string> $headers): Response
    {
	    $this->headers = $headers;

	    return $this;
    }

	public function getHeaders(): Map<satring, string>
    {
	    return $this->headers;
    }

	public function setHeader(string $name, string $value): Response
    {
	    $this->headers[$name] = $value;

	    return $this;
    }

    public function getHeader(string $name, $default = '')
	{
		if ($this->headers->contains($name)) {
			return $this->headers[$name];
		}

		return $default;
	}

	public function setCookies(Map<string, Cookie> $cookies): Response
    {
	    $this->cookies = $cookies;

	    return $this;
    }

	public function getCookies(): Map<string, string>
    {
	    return $this->cookies;
    }

	public function setCookie(Cookie $cookie): Response
    {
	    $this->cookies[$cookie->getName()] = $cookie;

	    return $this;
    }

    public function getCookie(string $cookieName)
	{
		if ($this->cookies->contains($cookieName)) {
			return $this->cookies[$cookieName];
		}

		return null;
	}

	public function setProtocolVersion(int $major, int $minor = 0): Response
	{
		$this->protocolVersion = $major.'.'.$minor;

		return $this;
	}

	public function getProtocolVersion(): string
	{
		return $this->protocolVersion;
	}

    public function __toString(): string
    {
        return $this->body;
    }

}
