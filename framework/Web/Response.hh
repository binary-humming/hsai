<?hh //strict

namespace HSAI\Web;

use \HSAI\ResponseInterface;

class Response implements ResponseInterface
{

    protected string $body = '';

	protected \stdClass $bodyObject;

    protected Map $headers;

	protected Map $cookies;

    protected string $statusCode = 200;

    protected string $satatusCodeMessage = 'OK';

	public function __construct()
	{
		$this->bodyObject = new \stdClass();
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

    public function getBodyObject(): \stdClass
    {
		return $this->bodyObject;
	}

    public function __toString(): string
    {
        return $this->body;
    }

}
