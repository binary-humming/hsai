<?hh //strict

namespace HSAI\CLI;

use \HSAI\ResponseInterface;

class Response implements ResponseInterface
{

    protected string $body = '';

	protected \sdtClass $bodyObject;

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

	public function toString(): string
    {
	    return $this->body;
    }

}
