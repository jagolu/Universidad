<?php

/* sites/all/themes/d8w3css/templates/views/views-view.html.twig */
class __TwigTemplate_be5e78282a5b1bf3a7d0bbf4af783041a69825a280fda9e46dc4b120778a3327 extends Twig_Template
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
        $tags = array("set" => 34, "if" => 45);
        $filters = array("clean_class" => 37);
        $functions = array();

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('set', 'if'),
                array('clean_class'),
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

        // line 34
        $context["classes"] = array(0 => "w3-row", 1 => "view", 2 => ("view-" . \Drupal\Component\Utility\Html::getClass(        // line 37
($context["id"] ?? null))), 3 => ("view-id-" .         // line 38
($context["id"] ?? null)), 4 => ("view-display-id-" .         // line 39
($context["display_id"] ?? null)), 5 => ((        // line 40
($context["dom_id"] ?? null)) ? (("js-view-dom-id-" . ($context["dom_id"] ?? null))) : ("")));
        // line 43
        echo "<div";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["attributes"] ?? null), "addClass", array(0 => ($context["classes"] ?? null)), "method"), "html", null, true));
        echo ">
  ";
        // line 44
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["title_prefix"] ?? null), "html", null, true));
        echo "
  ";
        // line 45
        if (($context["title"] ?? null)) {
            // line 46
            echo "    ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["title"] ?? null), "html", null, true));
            echo "
  ";
        }
        // line 48
        echo "  ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["title_suffix"] ?? null), "html", null, true));
        echo "
  ";
        // line 49
        if (($context["header"] ?? null)) {
            // line 50
            echo "    <header class=\"view-header\">
      ";
            // line 51
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["header"] ?? null), "html", null, true));
            echo "
    </header>
  ";
        }
        // line 54
        echo "  ";
        if (($context["exposed"] ?? null)) {
            // line 55
            echo "    <div class=\"view-filters form-group\">
      ";
            // line 56
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["exposed"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        }
        // line 59
        echo "  ";
        if (($context["attachment_before"] ?? null)) {
            // line 60
            echo "    <div class=\"attachment attachment-before\">
      ";
            // line 61
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["attachment_before"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        }
        // line 64
        echo "
  ";
        // line 65
        if (($context["rows"] ?? null)) {
            // line 66
            echo "    <div class=\"view-content\">
      ";
            // line 67
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["rows"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        } elseif (        // line 69
($context["empty"] ?? null)) {
            // line 70
            echo "    <div class=\"view-empty\">
      ";
            // line 71
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["empty"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        }
        // line 74
        echo "
  ";
        // line 75
        if (($context["pager"] ?? null)) {
            // line 76
            echo "    ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["pager"] ?? null), "html", null, true));
            echo "
  ";
        }
        // line 78
        echo "  ";
        if (($context["attachment_after"] ?? null)) {
            // line 79
            echo "    <div class=\"attachment attachment-after\">
      ";
            // line 80
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["attachment_after"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        }
        // line 83
        echo "  ";
        if (($context["more"] ?? null)) {
            // line 84
            echo "    ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["more"] ?? null), "html", null, true));
            echo "
  ";
        }
        // line 86
        echo "  ";
        if (($context["footer"] ?? null)) {
            // line 87
            echo "    <footer class=\"view-footer\">
      ";
            // line 88
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["footer"] ?? null), "html", null, true));
            echo "
    </footer>
  ";
        }
        // line 91
        echo "  ";
        if (($context["feed_icons"] ?? null)) {
            // line 92
            echo "    <div class=\"feed-icons\">
      ";
            // line 93
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["feed_icons"] ?? null), "html", null, true));
            echo "
    </div>
  ";
        }
        // line 96
        echo "</div>
";
    }

    public function getTemplateName()
    {
        return "sites/all/themes/d8w3css/templates/views/views-view.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  186 => 96,  180 => 93,  177 => 92,  174 => 91,  168 => 88,  165 => 87,  162 => 86,  156 => 84,  153 => 83,  147 => 80,  144 => 79,  141 => 78,  135 => 76,  133 => 75,  130 => 74,  124 => 71,  121 => 70,  119 => 69,  114 => 67,  111 => 66,  109 => 65,  106 => 64,  100 => 61,  97 => 60,  94 => 59,  88 => 56,  85 => 55,  82 => 54,  76 => 51,  73 => 50,  71 => 49,  66 => 48,  60 => 46,  58 => 45,  54 => 44,  49 => 43,  47 => 40,  46 => 39,  45 => 38,  44 => 37,  43 => 34,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "sites/all/themes/d8w3css/templates/views/views-view.html.twig", "C:\\Users\\Javi\\Dropbox\\UGR\\4\\2_Cuatrimestre\\Sistemas_Cooperativos_y_Gestion_de_Contenidos\\drupal\\sites\\all\\themes\\d8w3css\\templates\\views\\views-view.html.twig");
    }
}
