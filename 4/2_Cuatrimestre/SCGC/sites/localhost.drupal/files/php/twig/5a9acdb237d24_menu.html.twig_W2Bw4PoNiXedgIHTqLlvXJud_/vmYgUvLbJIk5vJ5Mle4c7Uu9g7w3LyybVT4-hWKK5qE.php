<?php

/* sites/all/themes/d8w3css/templates/navigation/menu.html.twig */
class __TwigTemplate_11dd39a4b97db4803bd799621f6353350c78cf7480da99920bcb779b1701d80b extends Twig_Template
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
        $tags = array("import" => 21, "macro" => 27, "set" => 30, "if" => 39, "for" => 45);
        $filters = array("clean_class" => 31);
        $functions = array("link" => 68);

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('import', 'macro', 'set', 'if', 'for'),
                array('clean_class'),
                array('link')
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

        // line 21
        $context["menus"] = $this;
        // line 26
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($context["menus"]->getmenu_links(($context["items"] ?? null), ($context["attributes"] ?? null), 0, ($context["menu_name"] ?? null))));
        echo "
";
    }

    // line 27
    public function getmenu_links($__items__ = null, $__attributes__ = null, $__menu_level__ = null, $__menu_name__ = null, ...$__varargs__)
    {
        $context = $this->env->mergeGlobals(array(
            "items" => $__items__,
            "attributes" => $__attributes__,
            "menu_level" => $__menu_level__,
            "menu_name" => $__menu_name__,
            "varargs" => $__varargs__,
        ));

        $blocks = array();

        ob_start();
        try {
            // line 28
            echo "  ";
            $context["menus"] = $this;
            // line 29
            echo "  ";
            // line 30
            $context["menu_classes"] = array(0 => ("ul-parent ul-parent-" . \Drupal\Component\Utility\Html::getClass(            // line 31
($context["menu_name"] ?? null))));
            // line 34
            echo "  ";
            // line 35
            $context["submenu_classes"] = array(0 => ("ul-child ul-child-" . \Drupal\Component\Utility\Html::getClass(            // line 36
($context["menu_name"] ?? null))));
            // line 39
            echo "  ";
            if (($context["items"] ?? null)) {
                // line 40
                echo "    ";
                if ((($context["menu_level"] ?? null) == 0)) {
                    // line 41
                    echo "      <ul ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["attributes"] ?? null), "addClass", array(0 => ($context["menu_classes"] ?? null)), "method"), "html", null, true));
                    echo " role=\"menu\">
    ";
                } else {
                    // line 43
                    echo "      <ul ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($this->getAttribute(($context["attributes"] ?? null), "removeClass", array(0 => ($context["menu_classes"] ?? null)), "method"), "addClass", array(0 => ($context["submenu_classes"] ?? null)), "method"), "html", null, true));
                    echo " role=\"menu\">
    ";
                }
                // line 45
                echo "    ";
                $context['_parent'] = $context;
                $context['_seq'] = twig_ensure_traversable(($context["items"] ?? null));
                foreach ($context['_seq'] as $context["_key"] => $context["item"]) {
                    // line 46
                    echo "      ";
                    // line 47
                    $context["item_classes"] = array(0 => ("li-item li-item-" . \Drupal\Component\Utility\Html::getClass(                    // line 48
($context["menu_name"] ?? null))), 1 => (($this->getAttribute(                    // line 49
$context["item"], "is_expanded", array())) ? ("li-expanded") : ("")), 2 => ((($this->getAttribute(                    // line 50
$context["item"], "is_expanded", array()) && (($context["menu_level"] ?? null) == 0))) ? ("li-parent") : ("")), 3 => (($this->getAttribute(                    // line 51
$context["item"], "in_active_trail", array())) ? ("active") : ("")));
                    // line 54
                    echo "     ";
                    if (((($context["menu_level"] ?? null) == 0) && $this->getAttribute($context["item"], "is_expanded", array()))) {
                        // line 55
                        echo "        <li";
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($this->getAttribute($context["item"], "attributes", array()), "addClass", array(0 => ($context["item_classes"] ?? null)), "method"), "html", null, true));
                        echo " role=\"none\">
        <a href=\"#\" class=\"w3-button tMenu toggle-parent\" aria-haspopup=\"true\">";
                        // line 56
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($context["item"], "title", array()), "html", null, true));
                        echo " <span class=\"fa fa-chevron-down dropdown-arrow\"></span></a>
      ";
                    } elseif (((                    // line 57
($context["menu_level"] ?? null) != 0) && $this->getAttribute($context["item"], "is_expanded", array()))) {
                        // line 58
                        echo "        <li";
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($this->getAttribute($context["item"], "attributes", array()), "addClass", array(0 => ($context["item_classes"] ?? null)), "method"), "html", null, true));
                        echo " role=\"none\">
        <a href=\"#\" class=\"w3-button tMenu toggle-child\" aria-haspopup=\"true\">";
                        // line 59
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($context["item"], "title", array()), "html", null, true));
                        echo " <span class=\"fa fa-arrow-right right-arrow\"></span><span class=\" fa fa-chevron-down dropdown-arrow\"></span></a>
      ";
                    } else {
                        // line 61
                        echo "      ";
                        // line 62
                        $context["link_classes"] = array(0 => ("w3-button li-link li-link-" . \Drupal\Component\Utility\Html::getClass(                        // line 63
($context["menu_name"] ?? null))));
                        // line 66
                        echo "      <li";
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute($this->getAttribute($context["item"], "attributes", array()), "addClass", array(0 => ($context["item_classes"] ?? null)), "method"), "html", null, true));
                        echo " role=\"none\">
        ";
                        // line 67
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->env->getExtension('Drupal\Core\Template\TwigExtension')->getLink($this->getAttribute(                        // line 69
$context["item"], "title", array()), $this->getAttribute(                        // line 70
$context["item"], "url", array()), $this->getAttribute($this->getAttribute($this->getAttribute(                        // line 71
$context["item"], "attributes", array()), "removeClass", array(0 => ($context["item_classes"] ?? null)), "method"), "addClass", array(0 => ($context["link_classes"] ?? null)), "method")), "html", null, true));
                        // line 73
                        echo "
      ";
                    }
                    // line 75
                    echo "      ";
                    if ($this->getAttribute($context["item"], "below", array())) {
                        // line 76
                        echo "          ";
                        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar($context["menus"]->getmenu_links($this->getAttribute($context["item"], "below", array()), ($context["attributes"] ?? null), (($context["menu_level"] ?? null) + 1), ($context["menu_name"] ?? null))));
                        echo "
      ";
                    }
                    // line 78
                    echo "      </li>
    ";
                }
                $_parent = $context['_parent'];
                unset($context['_seq'], $context['_iterated'], $context['_key'], $context['item'], $context['_parent'], $context['loop']);
                $context = array_intersect_key($context, $_parent) + $_parent;
                // line 80
                echo "    </ul>
  ";
            }
        } catch (Exception $e) {
            ob_end_clean();

            throw $e;
        } catch (Throwable $e) {
            ob_end_clean();

            throw $e;
        }

        return ('' === $tmp = ob_get_clean()) ? '' : new Twig_Markup($tmp, $this->env->getCharset());
    }

    public function getTemplateName()
    {
        return "sites/all/themes/d8w3css/templates/navigation/menu.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  169 => 80,  162 => 78,  156 => 76,  153 => 75,  149 => 73,  147 => 71,  146 => 70,  145 => 69,  144 => 67,  139 => 66,  137 => 63,  136 => 62,  134 => 61,  129 => 59,  124 => 58,  122 => 57,  118 => 56,  113 => 55,  110 => 54,  108 => 51,  107 => 50,  106 => 49,  105 => 48,  104 => 47,  102 => 46,  97 => 45,  91 => 43,  85 => 41,  82 => 40,  79 => 39,  77 => 36,  76 => 35,  74 => 34,  72 => 31,  71 => 30,  69 => 29,  66 => 28,  51 => 27,  45 => 26,  43 => 21,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "sites/all/themes/d8w3css/templates/navigation/menu.html.twig", "C:\\Users\\Javi\\Dropbox\\UGR\\4\\2_Cuatrimestre\\Sistemas_Cooperativos_y_Gestion_de_Contenidos\\drupal\\sites\\all\\themes\\d8w3css\\templates\\navigation\\menu.html.twig");
    }
}
