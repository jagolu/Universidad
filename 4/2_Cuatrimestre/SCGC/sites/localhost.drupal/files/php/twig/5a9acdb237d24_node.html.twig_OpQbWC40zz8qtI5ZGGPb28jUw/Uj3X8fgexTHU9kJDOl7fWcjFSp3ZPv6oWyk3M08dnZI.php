<?php

/* sites/all/themes/magazine_lite/templates/node.html.twig */
class __TwigTemplate_512c3dc3928e8248677a735eb3e08b68c1a7e4538d913ad2061722a3b205b09a extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
            'node_side' => array($this, 'block_node_side'),
            'header_top' => array($this, 'block_header_top'),
            'title_area' => array($this, 'block_title_area'),
            'meta_area' => array($this, 'block_meta_area'),
            'content' => array($this, 'block_content'),
            'content_bottom' => array($this, 'block_content_bottom'),
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $tags = array("set" => 70, "block" => 84, "if" => 92, "trans" => 108);
        $filters = array("clean_class" => 72);
        $functions = array("attach_library" => 80);

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('set', 'block', 'if', 'trans'),
                array('clean_class'),
                array('attach_library')
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

        // line 70
        $context["classes"] = array(0 => "node", 1 => ("node--type-" . \Drupal\Component\Utility\Html::getClass($this->getAttribute(        // line 72
($context["node"] ?? null), "bundle", array()))), 2 => (($this->getAttribute(        // line 73
($context["node"] ?? null), "isPromoted", array(), "method")) ? ("node--promoted") : ("")), 3 => (($this->getAttribute(        // line 74
($context["node"] ?? null), "isSticky", array(), "method")) ? ("node--sticky") : ("")), 4 => (( !$this->getAttribute(        // line 75
($context["node"] ?? null), "isPublished", array(), "method")) ? ("node--unpublished") : ("")), 5 => ((        // line 76
($context["view_mode"] ?? null)) ? (("node--view-mode-" . \Drupal\Component\Utility\Html::getClass(($context["view_mode"] ?? null)))) : ("")), 6 => "clearfix");
        // line 80
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->env->getExtension('Drupal\Core\Template\TwigExtension')->attachLibrary("classy/node"), "html", null, true));
        echo "
";
        // line 81
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->env->getExtension('Drupal\Core\Template\TwigExtension')->attachLibrary("magazine_lite/node"), "html", null, true));
        echo "
<article";
        // line 82
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["attributes"] ?? null), "addClass", array(0 => ($context["classes"] ?? null)), "method"), "html", null, true));
        echo ">
  <div class=\"node__container\">
    ";
        // line 84
        $this->displayBlock('node_side', $context, $blocks);
        // line 86
        echo "    <div";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["content_attributes"] ?? null), "addClass", array(0 => "node__main-content", 1 => "clearfix"), "method"), "html", null, true));
        echo ">
      ";
        // line 87
        $this->displayBlock('header_top', $context, $blocks);
        // line 89
        echo "      <header class=\"node__header\">
        ";
        // line 90
        $this->displayBlock('title_area', $context, $blocks);
        // line 103
        echo "        ";
        $this->displayBlock('meta_area', $context, $blocks);
        // line 119
        echo "      </header>
      ";
        // line 120
        $this->displayBlock('content', $context, $blocks);
        // line 123
        echo "      ";
        $this->displayBlock('content_bottom', $context, $blocks);
        // line 125
        echo "    </div>
  </div>
</article>
";
    }

    // line 84
    public function block_node_side($context, array $blocks = array())
    {
        // line 85
        echo "    ";
    }

    // line 87
    public function block_header_top($context, array $blocks = array())
    {
        // line 88
        echo "      ";
    }

    // line 90
    public function block_title_area($context, array $blocks = array())
    {
        // line 91
        echo "          ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["title_prefix"] ?? null), "html", null, true));
        echo "
          ";
        // line 92
        if ( !($context["page"] ?? null)) {
            // line 93
            echo "            <h2";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["title_attributes"] ?? null), "addClass", array(0 => "node__title"), "method"), "html", null, true));
            echo ">
              <a href=\"";
            // line 94
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["url"] ?? null), "html", null, true));
            echo "\" rel=\"bookmark\">";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["label"] ?? null), "html", null, true));
            echo "</a>
            </h2>
          ";
        } else {
            // line 97
            echo "            <h2";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["title_attributes"] ?? null), "addClass", array(0 => "node__title title sr-only"), "method"), "html", null, true));
            echo ">
              ";
            // line 98
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["label"] ?? null), "html", null, true));
            echo "
            </h2>
          ";
        }
        // line 101
        echo "          ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["title_suffix"] ?? null), "html", null, true));
        echo "
        ";
    }

    // line 103
    public function block_meta_area($context, array $blocks = array())
    {
        // line 104
        echo "          ";
        if (($context["display_submitted"] ?? null)) {
            // line 105
            echo "            <div class=\"node__meta\">
              ";
            // line 106
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["author_picture"] ?? null), "html", null, true));
            echo "
              <span";
            // line 107
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["author_attributes"] ?? null), "addClass", array(0 => "node__submitted-info"), "method"), "html", null, true));
            echo ">
                ";
            // line 108
            echo t("<span class=\"node__submitted-info-text\">By</span> @author_name on 
                  <span class=\"node__submitted-date\">
                    @date
                  </span>", array("@author_name" =>             // line 109
($context["author_name"] ?? null), "@date" =>             // line 111
($context["date"] ?? null), ));
            // line 114
            echo "              </span>
              ";
            // line 115
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["metadata"] ?? null), "html", null, true));
            echo "
            </div>
          ";
        }
        // line 118
        echo "        ";
    }

    // line 120
    public function block_content($context, array $blocks = array())
    {
        // line 121
        echo "        ";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["content"] ?? null), "html", null, true));
        echo "
      ";
    }

    // line 123
    public function block_content_bottom($context, array $blocks = array())
    {
        // line 124
        echo "      ";
    }

    public function getTemplateName()
    {
        return "sites/all/themes/magazine_lite/templates/node.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  206 => 124,  203 => 123,  196 => 121,  193 => 120,  189 => 118,  183 => 115,  180 => 114,  178 => 111,  177 => 109,  173 => 108,  169 => 107,  165 => 106,  162 => 105,  159 => 104,  156 => 103,  149 => 101,  143 => 98,  138 => 97,  130 => 94,  125 => 93,  123 => 92,  118 => 91,  115 => 90,  111 => 88,  108 => 87,  104 => 85,  101 => 84,  94 => 125,  91 => 123,  89 => 120,  86 => 119,  83 => 103,  81 => 90,  78 => 89,  76 => 87,  71 => 86,  69 => 84,  64 => 82,  60 => 81,  56 => 80,  54 => 76,  53 => 75,  52 => 74,  51 => 73,  50 => 72,  49 => 70,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "sites/all/themes/magazine_lite/templates/node.html.twig", "C:\\Users\\Javi\\Dropbox\\UGR\\4\\2_Cuatrimestre\\Sistemas_Cooperativos_y_Gestion_de_Contenidos\\drupal\\sites\\all\\themes\\magazine_lite\\templates\\node.html.twig");
    }
}
