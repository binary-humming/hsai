<?hh // strict

namespace HSAI\Web\Components;

use \HSAI\AbstractComponent;
use \HSAI\EnvironmentInterface;

class ResponseBuilder extends AbstractComponent
{

	public function invoke(EnvironmentInterface $environment)
	{
		$this->next($environment);

		$response = $environment->getResponse();

//		if ($response->getBodyObject() instanceof \stdClass) {
//			$request = $environment->getRequest();
//
//			$acceptedFormats = $request->getHeader('Accept');
//
//			//TODO: call response formatter
//		}

		foreach ($response->getHeaders() as $header => $value) {
			header($header.': '.$value);
		}

		foreach ($response->getCookies() as $cookie) {
			setcookie($cookie->getName(), $cookie->getValue(), $cookie->getExpire(), $cookie->getPath(), $cookie->getDomain(), $cookie->isSecure(), $cookie->isHttpOnly());
		}

		http_response_code($response->getStatusCode());
	}

}