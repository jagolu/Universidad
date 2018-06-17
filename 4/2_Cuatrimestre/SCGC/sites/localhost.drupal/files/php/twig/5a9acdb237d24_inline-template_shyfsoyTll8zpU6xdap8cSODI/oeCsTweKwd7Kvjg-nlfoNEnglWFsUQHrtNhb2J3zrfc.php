<?php

/* {# inline_template_start #}No has entregado el trabajo: {{ raw_arguments.field_trabajo_target_id }}<p></p>
<a href="/node/add/entrega">Entregar trabajo</a> */
class __TwigTemplate_9c33c94e2e4a0e492b7889fa0698f2615e3e12c052231d4668f03822ab957b93 extends Twig_Template
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
        echo "No has entregado el trabajo: ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["raw_arguments"] ?? null), "field_trabajo_target_id", array()), "html", null, true));
        echo "<p></p>
<a href=\"/node/add/entrega\">Entregar trabajo</a>";
    }

    public function getTemplateName()
    {
        return "{# inline_template_start #}No has entregado el trabajo: {{ raw_arguments.field_trabajo_target_id }}<p></p>
<a href=\"/node/add/entrega\">Entregar trabajo</a>";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  44 => 1,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "{# inline_template_start #}No has entregado el trabajo: {{ raw_arguments.field_trabajo_target_id }}<p></p>
<a href=\"/node/add/entrega\">Entregar trabajo</a>", "");
    }
}
