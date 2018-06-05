<?php

/* {# inline_template_start #}<p>No has entregado el trabajo: {{ raw_arguments.nid }}</p>
<a href="drupal/node/add/entrega_trabajo?{{ raw_arguments.nid }}">Entregar trabajo</a> */
class __TwigTemplate_fa0bd6972b462f39bb1801d4d3df57ed25a76aa76b3619fb822295f58f2fe43f extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $tags = array();
        $filters = array();
        $functions = array();

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array(),
                array(),
                array()
            );
        } catch (Twig_Sandbox_SecurityError $e) {
            $e->setSourceContext($this->getSourceContext());

            if ($e instanceof Twig_Sandbox_SecurityNotAllowedTagError && isset($tags[$e->getTagName()])) {
                $e->setTemplateLine($tags[$e->getTagName()]);
            } elseif ($e instanceof Twig_Sandbox_SecurityNotAllowedFilterError && isset($filters[$e->getFilterName()])) {
                $e->setTemplateLine($filters[$e->getFilterName()]);
            } elseif ($e instanceof Twig_Sandbox_SecurityNotAllowedFunctionError && isset($functions[$e->getFunctionName()])) {
                $e->setTemplateLine($functions[$e->getFunctionName()]);
            }

            throw $e;
        }

        // line 1
        echo "<p>No has entregado el trabajo: ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["raw_arguments"] ?? null), "nid", array()), "html", null, true));
        echo "</p>
<a href=\"drupal/node/add/entrega_trabajo?";
        // line 2
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["raw_arguments"] ?? null), "nid", array()), "html", null, true));
        echo "\">Entregar trabajo</a>";
    }

    public function getTemplateName()
    {
        return "{# inline_template_start #}<p>No has entregado el trabajo: {{ raw_arguments.nid }}</p>
<a href=\"drupal/node/add/entrega_trabajo?{{ raw_arguments.nid }}\">Entregar trabajo</a>";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  49 => 2,  44 => 1,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "{# inline_template_start #}<p>No has entregado el trabajo: {{ raw_arguments.nid }}</p>
<a href=\"drupal/node/add/entrega_trabajo?{{ raw_arguments.nid }}\">Entregar trabajo</a>", "");
    }
}
