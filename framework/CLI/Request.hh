<?hh //strict

namespace HSAI\CLI;

use \HSAI\RequestInterface;

/**
 * Class Request
 *
 * @package HSAI\CLI
 */
class Request implements RequestInterface
{

	protected string $id = '';

	protected Set<string> $flags;

	protected Map<string, string> $options;

	protected Set<string> $arguments;

	public function __construct()
	{
		$this->flags = Set{};
		$this->options = Map{};
		$this->arguments = Set{};
	}

	/**
	 * Sets the id of the request
	 */
	public function setId(string $id): Request
    {
		$this->id = $id;

	    return $this;
    }

	/**
	 * Returns the id of the request
	 */
	public function getId(): string
    {
	    return $this->id;
    }

	/**
	 * Sets the request flags
	 */
	public function setFlags(Set<strings> $flags): Request
	{
		$this->flags = $flags;

		return $this;
	}

	/**
	 * Returns the request flags
	 */
	public function getFlags(): Set<strings>
	{
		return $this->flags;
	}

	/**
	 * Adds a new flag to the flags collection
	 */
	public function addFlag(string $flag): Request
	{
		$this->flags->add($flag);

		return $this;
	}

	/**
	 * Returns true or false whether a flag exists or not
	 */
	public function doesFlagExists(string $flag): boolean
	{
		return $this->flags->contains($flag);
	}

	/**
	 * Sets the request arguments
	 */
	public function setArguments(Set<strings> $arguments): Request
	{
		$this->arguments = $arguments;

		return $this;
	}

	/**
	 * Returns the request arguments
	 */
	public function getArguments(): Set<strings>
	{
		return $this->arguments;
	}

	/**
	 * Adds a new argument to the arguments collection
	 */
	public function addArgument(string $argument): Request
	{
		$this->arguments->add($argument);

		return $this;
	}

	/**
	 * Returns true or false whether an argument exists or not
	 */
	public function doesArgumentExists(string $argument): boolean
	{
		return $this->arguments->contains($argument);
	}

	/**
	 * Sets the request options
	 */
	public function setOptions(Map<strings, string> $options): Request
	{
		$this->options = $options;

		return $this;
	}

	/**
	 * Returns the request options
	 */
	public function getOptions(): Map<strings, string>
	{
		return $this->options;
	}

	/**
	 * Adds a new option to the options collection
	 */
	public function addOption(string $option, string $value): Request
	{
		$this->options[$option] = $value;

		return $this;
	}

	/**
	 * Returns the value of an option, is the option does not exist a default value will be returned, if not default value is provided an empty string will be returned.
	 */
	public function getOptionValue(string $option, string $default = ''): string
	{
		if ($this->options->contains($option) == true) {
			return $this->options[$option];
		}

		return $default;
	}

	/**
	 * Returns true or false whether an option exists or not
	 */
	public function doesOptionExists(string $option): boolean
	{
		return $this->options->contains($option);
	}



}
