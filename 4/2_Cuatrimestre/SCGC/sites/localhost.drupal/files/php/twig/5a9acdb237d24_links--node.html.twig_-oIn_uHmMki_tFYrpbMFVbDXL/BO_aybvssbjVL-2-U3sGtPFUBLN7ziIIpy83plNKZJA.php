<?php

/* sites/all/themes/d8w3css/templates/content/links--node.html.twig */
class __TwigTemplate_981c5283cad5377bb783bc6e21e0359f5a9cfe7bf6a5014ee2da024af34d036e extends Twig_Template
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
        $tags = array("if" => 36, "include" => 37);
        $filters = array();
        $functions = array();

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('if', 'include'),
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

        // line 36
        if (($context["links"] ?? null)) {
            // line 37
            echo "    ";
            $this->loadTemplate("links.html.twig", "sites/all/themes/d8w3css/templates/content/links--node.html.twig", 37)->display($context);
        }
    }

    public function getTemplateName()
    {
        return "sites/all/themes/d8w3css/templates/content/links--node.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  45 => 37,  43 => 36,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "sites/all/themes/d8w3css/templates/content/links--node.html.twig", "C:\\Users\\Javi\\Dropbox\\UGR\\4\\2_Cuatrimestre\\Sistemas_Cooperativos_y_Gestion_de_Contenidos\\drupal\\sites\\all\\themes\\d8w3css\\templates\\content\\links--node.html.twig");
    }
}
