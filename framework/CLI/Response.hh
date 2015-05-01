<?hh //strict

namespace HSAI\CLI;

use \HSAI\ResponseInterface;

class Response implements ResponseInterface
{

    protected string $content = '';

	protected \sdtClass $contentObject;

	public function __construct()
	{
		$this->bodyObject = new \stdClass();
	}

    public function setContent(string $content): Response
    {
        $this->content = $content;

        return $this;
    }

    public function getContent(): string
    {
        return $this->content;
    }

	public function setContentObject(\stdClass $content): Response
    {
		$this->contentObject = $content;

		return $this;
	}

    public function getContentObject(): \stdClass
    {
		return $this->contentObject;
	}

	public function __toString(): string
    {
	    return $this->content;
    }

}
