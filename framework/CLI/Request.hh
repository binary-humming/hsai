<?hh //strict

namespace HSAI\CLI;

use \HSAI\RequestInterface;

class Request implements RequestInterface
{

	// The content of the request body
	protected string $body = '';

	// A unique identifier for the request.
	protected string $id = '';


	public function __construct()
	{
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
