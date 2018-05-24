<?php

/* sites/all/themes/d8w3css/templates/layout/page.html.twig */
class __TwigTemplate_3788d5ab716367ec7abd92673acfb62746930740c97c2bf94e3809fbd3121292 extends Twig_Template
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
        $tags = array("if" => 57);
        $filters = array("t" => 59);
        $functions = array();

        try {
            $this->env->getExtension('Twig_Extension_Sandbox')->checkSecurity(
                array('if'),
                array('t'),
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

        // line 57
        echo "  ";
        if ($this->getAttribute(($context["page"] ?? null), "primary_menu_vertical", array())) {
            // line 58
            echo "  <!-- Start: Main Navigation - Vertical -->
  <div id=\"main-navigation-v\" class=\"main-navigation-wrapper w3-sidebar w3-bar-block w3-animate-left w3-card w3-theme ";
            // line 59
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_primary_menu"] ?? null), "html", null, true));
            echo "\" role=\"navigation\" aria-label=\"";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Main Navigation")));
            echo "\" >
    <div id=\"main-navigation-inner-v\" class=\"main-navigation-inner-v\">
      <i id=\"close-nav\" class=\"close-nav fa fa-bars w3-button w3-bar-block w3-xlarge w3-theme ";
            // line 61
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_primary_menu"] ?? null), "html", null, true));
            echo "\"></i>
        ";
            // line 62
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "primary_menu_vertical", array()), "html", null, true));
            echo "
    </div>
  </div>
  <!-- End: Main Navigation - Vertical -->
";
        }
        // line 67
        echo "<!-- Start: Page Wrapper -->
<div class=\"page-wrapper w3-col w3-clear w3-animate-opacity w3-text-theme ";
        // line 68
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_page_wrapper"] ?? null), "html", null, true));
        echo " \">
  <!-- Start: Header -->
  <header id=\"header\" class=\"w3-col w3-clear w3-theme-l4 ";
        // line 70
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_header"] ?? null), "html", null, true));
        echo "\" role=\"banner\" aria-label=\"";
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Site header")));
        echo "\">
    <div id=\"header-inner\" class=\"d8-fade w3-container header-inner ";
        // line 71
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
        echo "\">
      ";
        // line 72
        if ($this->getAttribute(($context["page"] ?? null), "primary_menu_vertical", array())) {
            // line 73
            echo "        <div id=\"open-nav-inner\" class=\"open-nav-inner w3-opacity w3-hover-opacity-off w3-left fa fa-bars w3-button w3-left-align w3-xxlarge w3-theme ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_primary_menu"] ?? null), "html", null, true));
            echo "\"></div>
      ";
        }
        // line 75
        echo "      ";
        if ($this->getAttribute(($context["page"] ?? null), "header", array())) {
            // line 76
            echo "        ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "header", array()), "html", null, true));
            echo "
      ";
        }
        // line 78
        echo "    </div>
  </header>
  <!-- End: Header -->
  ";
        // line 81
        if ($this->getAttribute(($context["page"] ?? null), "primary_menu", array())) {
            // line 82
            echo "  <!-- Start: Main Navigation - Horizontal -->
  <div id=\"main-navigation-h\" class=\"w3-col w3-clear main-navigation-wrapper w3-card w3-theme ";
            // line 83
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_primary_menu"] ?? null), "html", null, true));
            echo "\" role=\"navigation\" aria-label=\"";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(t("Main Navigation")));
            echo "\" >
    <div id=\"main-navigation-inner-h\" class=\"d8-fade w3-row main-navigation-inner-h ";
            // line 84
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        <i class=\"mobile-nav fa fa-bars w3-hide-large w3-button w3-block w3-right-align w3-xxlarge w3-theme ";
            // line 85
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_primary_menu"] ?? null), "html", null, true));
            echo "\"></i>
        ";
            // line 86
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "primary_menu", array()), "html", null, true));
            echo "
    </div>
  </div>
  <!-- End: Main Navigation - Horizontal -->
  ";
        }
        // line 91
        echo "  ";
        if ((($context["is_front"] ?? null) && $this->getAttribute(($context["page"] ?? null), "welcome_text", array()))) {
            // line 92
            echo "    <!-- Start: Welcome Text -->
    <div id=\"welcome-text\" class=\"w3-col w3-clear w3-theme-l5 ";
            // line 93
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_welcome_text"] ?? null), "html", null, true));
            echo "\">
      <div id=\"welcome-text-inner\" class=\"d8-fade w3-row welcome-text-inner ";
            // line 94
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        ";
            // line 95
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "welcome_text", array()), "html", null, true));
            echo "
      </div>
    </div>
    <!-- End: Welcome Text -->
  ";
        }
        // line 100
        echo "  ";
        if ($this->getAttribute(($context["page"] ?? null), "highlighted", array())) {
            // line 101
            echo "    <!-- Start: Highlighted -->
    <div id=\"highlighted\" class=\"w3-col w3-clear w3-theme-l2 ";
            // line 102
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_highlighted"] ?? null), "html", null, true));
            echo "\">
      <div id=\"highlighted-inner\" class=\"d8-fade w3-row highlighted-inner ";
            // line 103
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        ";
            // line 104
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "highlighted", array()), "html", null, true));
            echo "
      </div>
    </div>
    <!-- End: Highlighted -->
  ";
        }
        // line 109
        echo "  ";
        if (($context["is_front"] ?? null)) {
            // line 110
            echo "    ";
            if ((($this->getAttribute(($context["page"] ?? null), "top_first", array()) || $this->getAttribute(($context["page"] ?? null), "top_second", array())) || $this->getAttribute(($context["page"] ?? null), "top_third", array()))) {
                // line 111
                echo "      <!-- Start: Top Container -->
      <div id=\"top-container\" class=\"w3-col w3-clear w3-theme-l4 ";
                // line 112
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_top_container"] ?? null), "html", null, true));
                echo "\">
        <div id=\"top-container-inner\" class=\"w3-row-padding w3-padding-large top-container-inner ";
                // line 113
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
                echo "\">
          ";
                // line 114
                if ($this->getAttribute(($context["page"] ?? null), "top_first", array())) {
                    // line 115
                    echo "            <!-- Start: Top container first region -->
            <div class=\"";
                    // line 116
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["top_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["top_region"] ?? null)) ? ("top-region") : (""))));
                    echo " first-top\" >
              <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l5 ";
                    // line 117
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_top_first"] ?? null), "html", null, true));
                    echo "\">
               ";
                    // line 118
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "top_first", array()), "html", null, true));
                    echo "
              </div>
            </div>
            <!-- End: Top Container First -->
          ";
                }
                // line 123
                echo "          ";
                if ($this->getAttribute(($context["page"] ?? null), "top_second", array())) {
                    // line 124
                    echo "            <!-- Start: Top Container Second  -->
            <div class=\"";
                    // line 125
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["top_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["top_region"] ?? null)) ? ("top-region") : (""))));
                    echo " second-top\">
              <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l5 ";
                    // line 126
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_top_second"] ?? null), "html", null, true));
                    echo "\">
               ";
                    // line 127
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "top_second", array()), "html", null, true));
                    echo "
              </div>
            </div>
            <!-- End: Top Container Second -->
          ";
                }
                // line 132
                echo "          ";
                if ($this->getAttribute(($context["page"] ?? null), "top_third", array())) {
                    // line 133
                    echo "          <!-- Start: Top Container Third -->
          <div class=\"";
                    // line 134
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["top_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["top_region"] ?? null)) ? ("top-region") : (""))));
                    echo " third-top\">
            <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l5 ";
                    // line 135
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_top_third"] ?? null), "html", null, true));
                    echo "\">
              ";
                    // line 136
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "top_third", array()), "html", null, true));
                    echo "
            </div>
          </div>
          <!-- End: Top Container Third -->
          ";
                }
                // line 141
                echo "        </div>
      </div>
      <!-- End: Top container -->
    ";
            }
            // line 145
            echo "  ";
        }
        // line 146
        echo "  ";
        if (($this->getAttribute(($context["page"] ?? null), "page_title", array()) &&  !($context["is_front"] ?? null))) {
            // line 147
            echo "    <!-- Start: Page Title -->
    <div id=\"page-title\" class=\"w3-col w3-clear w3-theme-d5 ";
            // line 148
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_page_title"] ?? null), "html", null, true));
            echo "\">
      <div id=\"page-title-inner\" class=\"d8-fade w3-row page-title-inner ";
            // line 149
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        ";
            // line 150
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "page_title", array()), "html", null, true));
            echo "
      </div>
    </div>
    <!-- End: Page Title -- >
  ";
        }
        // line 155
        echo "  <!-- Start: Main -->
  <div id=\"main-container\" class=\"w3-col w3-clear w3-theme-l5 ";
        // line 156
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_main"] ?? null), "html", null, true));
        echo "\">
    <div id=\"main-container-inner\" class=\"w3-container main-container-inner ";
        // line 157
        echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
        echo "\">
      ";
        // line 158
        if ($this->getAttribute(($context["page"] ?? null), "breadcrumb", array())) {
            // line 159
            echo "        <!-- Breadcrumb -->
        <div class=\"";
            // line 160
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_breadcrumb"] ?? null), "html", null, true));
            echo "\">
          ";
            // line 161
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "breadcrumb", array()), "html", null, true));
            echo "
        </div>
        <!-- End: Breadcrumb -->
      ";
        }
        // line 165
        echo "      <!-- Start Main Container  -->
      <div class=\"w3-col w3-clear w3-row-padding\">
        ";
        // line 167
        if ($this->getAttribute(($context["page"] ?? null), "sidebar_first", array())) {
            // line 168
            echo "          <!-- Start Left SideBar -->
          <div class =\"";
            // line 169
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["sidebarfirst"] ?? null), "html", null, true));
            echo " ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["main_region"] ?? null)) ? ("main-region") : (""))));
            echo " first-sidebar\">
            <div class=\"d8-fade w3-card w3-round w3-sidebar-first w3-mobile ";
            // line 170
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_sidebar_first"] ?? null), "html", null, true));
            echo "\">
              ";
            // line 171
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "sidebar_first", array()), "html", null, true));
            echo "
            </div>
          </div>
          <!-- End: Left SideBar -->
        ";
        }
        // line 176
        echo "        ";
        if ($this->getAttribute(($context["page"] ?? null), "content", array())) {
            // line 177
            echo "          <!-- Start: Main Content -->
          <div class=\"";
            // line 178
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["content_w3css"] ?? null), "html", null, true));
            echo " ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["main_region"] ?? null)) ? ("main-region") : (""))));
            echo " w3css-content\">
            <div class=\"d8-fade w3-card w3-round w3-mobile  ";
            // line 179
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_content"] ?? null), "html", null, true));
            echo "\">
              ";
            // line 180
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "content", array()), "html", null, true));
            echo "
            </div>
          </div>
          <!-- End: Main Content -->
        ";
        }
        // line 185
        echo "        ";
        if ($this->getAttribute(($context["page"] ?? null), "sidebar_second", array())) {
            // line 186
            echo "          <!-- Start: Right SideBar -->
          <div class=\"";
            // line 187
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["sidebarsecond"] ?? null), "html", null, true));
            echo " ";
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["main_region"] ?? null)) ? ("main-region") : (""))));
            echo " second-sidebar\">
            <div class=\"d8-fade w3-card w3-round w3-sidebar-second w3-mobile ";
            // line 188
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_sidebar_second"] ?? null), "html", null, true));
            echo "\">
              ";
            // line 189
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "sidebar_second", array()), "html", null, true));
            echo "
            </div>
          </div>
          <!-- End: Right SideBar -->
        ";
        }
        // line 194
        echo "      </div>
      <!-- Endn: Main Container  -->
    </div>
  </div>
  <!-- End: Main -->
  ";
        // line 199
        if (($context["is_front"] ?? null)) {
            // line 200
            echo "    ";
            if (((($this->getAttribute(($context["page"] ?? null), "bottom_first", array()) || $this->getAttribute(($context["page"] ?? null), "bottom_second", array())) || $this->getAttribute(($context["page"] ?? null), "bottom_third", array())) || $this->getAttribute(($context["page"] ?? null), "bottom_forth", array()))) {
                // line 201
                echo "      <!-- Start: Bottom -->
      <div id=\"bottom-container\" class=\"w3-col w3-clear w3-theme-l2 ";
                // line 202
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_bottom_container"] ?? null), "html", null, true));
                echo "\">
        <div id=\"bottom-container-inner\" class=\"w3-row-padding w3-padding-large bottom-container-inner ";
                // line 203
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
                echo "\">
            ";
                // line 204
                if ($this->getAttribute(($context["page"] ?? null), "bottom_first", array())) {
                    // line 205
                    echo "              <!-- Start: Bottom First -->
              <div class=\"";
                    // line 206
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["bottom_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["bottom_region"] ?? null)) ? ("bottom-region") : (""))));
                    echo " first-bottom\">
                <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                    // line 207
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_bottom_first"] ?? null), "html", null, true));
                    echo "\">
                  ";
                    // line 208
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "bottom_first", array()), "html", null, true));
                    echo "
                </div>
              </div>
              <!-- End: Bottom First -->
            ";
                }
                // line 213
                echo "            ";
                if ($this->getAttribute(($context["page"] ?? null), "bottom_second", array())) {
                    // line 214
                    echo "              <!-- Start: Bottom Second -->
              <div class=\"";
                    // line 215
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["bottom_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["bottom_region"] ?? null)) ? ("bottom-region") : (""))));
                    echo " second-bottom\">
                <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                    // line 216
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_bottom_second"] ?? null), "html", null, true));
                    echo "\">
                  ";
                    // line 217
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "bottom_second", array()), "html", null, true));
                    echo "
                </div>
              </div>
              <!-- End: Bottom Second -->
            ";
                }
                // line 222
                echo "            ";
                if ($this->getAttribute(($context["page"] ?? null), "bottom_third", array())) {
                    // line 223
                    echo "              <!-- Start: Bottom Third  -->
              <div class=\"";
                    // line 224
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["bottom_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["bottom_region"] ?? null)) ? ("bottom-region") : (""))));
                    echo " third-bottom\">
                <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                    // line 225
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_bottom_third"] ?? null), "html", null, true));
                    echo "\">
                  ";
                    // line 226
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "bottom_third", array()), "html", null, true));
                    echo "
                </div>
              </div>
              <!-- End: Bottom Third -->
            ";
                }
                // line 231
                echo "            ";
                if ($this->getAttribute(($context["page"] ?? null), "bottom_forth", array())) {
                    // line 232
                    echo "              <!-- Start: Bottom Forth  -->
              <div class =\"";
                    // line 233
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["bottom_w3css"] ?? null), "html", null, true));
                    echo " ";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["bottom_region"] ?? null)) ? ("bottom-region") : (""))));
                    echo " forth-bottom\">
                <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                    // line 234
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_bottom_forth"] ?? null), "html", null, true));
                    echo "\">
                  ";
                    // line 235
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "bottom_forth", array()), "html", null, true));
                    echo "
                </div>
              </div>
              <!-- End: Bottom Forth -->
            ";
                }
                // line 240
                echo "        </div>
      </div>
      <!-- End: Bottom -->
    ";
            }
            // line 244
            echo "  ";
        }
        // line 245
        echo "  ";
        if ((($this->getAttribute(($context["page"] ?? null), "footer_first", array()) || $this->getAttribute(($context["page"] ?? null), "footer_second", array())) || $this->getAttribute(($context["page"] ?? null), "footer_third", array()))) {
            // line 246
            echo "    <!-- start: Footer -->
    <div id=\"footer-container\" class=\"w3-col w3-clear w3-theme-d3 ";
            // line 247
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_footer_container"] ?? null), "html", null, true));
            echo "\">
      <div id=\"footer-container-inner\" class=\"w3-row-padding w3-padding-large footer-container-inner ";
            // line 248
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">

        ";
            // line 250
            if ($this->getAttribute(($context["page"] ?? null), "footer_first", array())) {
                // line 251
                echo "          <!-- Start: Footer First  -->
          <div class=\"";
                // line 252
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["footer_w3css"] ?? null), "html", null, true));
                echo " ";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["footer_region"] ?? null)) ? ("footer-region") : (""))));
                echo " first-footer\">
            <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                // line 253
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_footer_first"] ?? null), "html", null, true));
                echo "\">
              ";
                // line 254
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_first", array()), "html", null, true));
                echo "
            </div>
          </div>
          <!-- End: Footer First -->
        ";
            }
            // line 259
            echo "        ";
            if ($this->getAttribute(($context["page"] ?? null), "footer_second", array())) {
                // line 260
                echo "          <!-- Start: Footer Second Region -->
          <div class=\"";
                // line 261
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["footer_w3css"] ?? null), "html", null, true));
                echo " ";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["footer_region"] ?? null)) ? ("footer-region") : (""))));
                echo " second-footer\">
            <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l5 ";
                // line 262
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_footer_second"] ?? null), "html", null, true));
                echo "\">
              ";
                // line 263
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_second", array()), "html", null, true));
                echo "
            </div>
          </div>
        <!-- End: Footer Second -->
        ";
            }
            // line 268
            echo "        ";
            if ($this->getAttribute(($context["page"] ?? null), "footer_third", array())) {
                // line 269
                echo "          <!-- Start: Footer Third -->
          <div class=\"";
                // line 270
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["footer_w3css"] ?? null), "html", null, true));
                echo " ";
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->renderVar(((($context["footer_region"] ?? null)) ? ("footer-region") : (""))));
                echo " third-footer\">
            <div class=\"d8-fade w3-card w3-round w3-mobile w3-theme-l4 ";
                // line 271
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_footer_third"] ?? null), "html", null, true));
                echo "\">
              ";
                // line 272
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_third", array()), "html", null, true));
                echo "
            </div>
          </div>
          <!-- End: Footer Third -->
        ";
            }
            // line 277
            echo "      </div>
    </div>
    <!-- End: Footer -->
  ";
        }
        // line 281
        echo "  ";
        if (($this->getAttribute(($context["page"] ?? null), "footer_menu", array()) || ($context["show_social_icon"] ?? null))) {
            // line 282
            echo "    <!-- Start: Footer Menu -->
    <div id=\"footer-menu\" class=\"w3-col w3-clear w3-card w3-theme-d4 ";
            // line 283
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_footer_menu"] ?? null), "html", null, true));
            echo "\">
      <div id=\"footer-menu-inner\" class=\"w3-row footer-menu-inner ";
            // line 284
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        ";
            // line 285
            if (($context["show_social_icon"] ?? null)) {
                // line 286
                echo "          <!-- Start: Social Media -->
          <div class=\"d8-fade w3-center w3-container w3-mobile social-media\">
            ";
                // line 288
                if (($context["facebook_url"] ?? null)) {
                    // line 289
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["facebook_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-blue w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\" ><i class=\"fa fa-facebook\"></i></a>
            ";
                }
                // line 291
                echo "            ";
                if (($context["twitter_url"] ?? null)) {
                    // line 292
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["twitter_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-blue w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\" ><i class=\"fa fa-twitter\"></i></a>
            ";
                }
                // line 294
                echo "            ";
                if (($context["pinterest_url"] ?? null)) {
                    // line 295
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["pinterest_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-red w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\"><i class=\"fa fa-pinterest\"></i></a>
            ";
                }
                // line 297
                echo "            ";
                if (($context["google_plus_url"] ?? null)) {
                    // line 298
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["google_plus_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-red w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\" ><i class=\"fa fa-google-plus\"></i></a>
            ";
                }
                // line 300
                echo "            ";
                if (($context["linkedin_url"] ?? null)) {
                    // line 301
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["linkedin_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-blue w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\"><i class=\"fa fa-linkedin\"></i></a>
            ";
                }
                // line 303
                echo "            ";
                if (($context["instagram_url"] ?? null)) {
                    // line 304
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["instagram_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-red w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\"><i class=\"fa fa-instagram\"></i></a>
            ";
                }
                // line 306
                echo "            ";
                if (($context["youtube_url"] ?? null)) {
                    // line 307
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["youtube_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-red w3-show-inline-block w3-xxlarge w3-padding\" target=\"_blank\"><i class=\"fa fa-youtube\"></i></a>
            ";
                }
                // line 309
                echo "            ";
                if (($context["drupal_url"] ?? null)) {
                    // line 310
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["drupal_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity-off w3-hover-text-blue w3-show-inline-block w3-xxlarge w3-padding-large\" target=\"_blank\" ><i class=\"fa fa-drupal\"></i></a>
            ";
                }
                // line 312
                echo "            ";
                if (($context["rss_url"] ?? null)) {
                    // line 313
                    echo "              <a href=\"";
                    echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["rss_url"] ?? null), "html", null, true));
                    echo "\" class=\"w3-opacity w3-hover-opacity w3-hover-text-red w3-show-inline-block w3-xxlarge w3-padding-large\" target=\"_blank\" ><i class=\"fa fa-rss\"></i></a>
            ";
                }
                // line 315
                echo "          </div>
          <!-- End: Social Media -->
        ";
            }
            // line 318
            echo "        <!-- Start: Bottom Menu -->
        ";
            // line 319
            if ($this->getAttribute(($context["page"] ?? null), "footer_menu", array())) {
                // line 320
                echo "          <div class=\"d8-fade w3-container w3-center w3-mobile\">
            ";
                // line 321
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, $this->getAttribute(($context["page"] ?? null), "footer_menu", array()), "html", null, true));
                echo "
          </div>
          <!-- End: Bottom Menu -->
        ";
            }
            // line 325
            echo "      </div>
    </div>
    <!-- End: Footer Menu -->
  ";
        }
        // line 329
        echo "  ";
        if ((($context["copyright_text"] ?? null) || ($context["show_credit_link"] ?? null))) {
            // line 330
            echo "    <!-- Start: Copyright -->
    <div id=\"copyright\" class=\"w3-col w3-clear w3-theme-d5 ";
            // line 331
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["color_copyright"] ?? null), "html", null, true));
            echo "\">
      <div id=\"copyright-inner\" class=\"w3-row copyright-inner ";
            // line 332
            echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["website_width"] ?? null), "html", null, true));
            echo "\">
        ";
            // line 333
            if (($context["copyright_text"] ?? null)) {
                // line 334
                echo "          <!-- Start: Copyright -->
          <div class=\"w3-half w3-container w3-mobile\">
            <p class=\"w3-section w3-left-align w3-opacity w3-hover-opacity-off\">";
                // line 336
                echo $this->env->getExtension('Twig_Extension_Sandbox')->ensureToStringAllowed($this->env->getExtension('Drupal\Core\Template\TwigExtension')->escapeFilter($this->env, ($context["copyright_text"] ?? null), "html", null, true));
                echo "</p>
          </div>
          <!-- End: Copyright -->
        ";
            }
            // line 340
            echo "        ";
            if (($context["show_credit_link"] ?? null)) {
                // line 341
                echo "          <!-- Start: Credit Link -->
          <div class=\"w3-half w3-container w3-mobile\">
            <p class=\"w3-section w3-right-align w3-opacity w3-hover-opacity-off\">Designed by: <a href=\"http://www.flashwebcenter.com\" title=\"Flash Web Center LLC\" target=\"_blank\">Flash Web Center LLC</a></p>
          </div>
          <!-- End: Credit Link -->
        ";
            }
            // line 347
            echo "      </div>
    </div>
    <!-- End: Copyright -->
  ";
        }
        // line 351
        echo "</div>
<!-- End: Page Wrapper -->
";
    }

    public function getTemplateName()
    {
        return "sites/all/themes/d8w3css/templates/layout/page.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  789 => 351,  783 => 347,  775 => 341,  772 => 340,  765 => 336,  761 => 334,  759 => 333,  755 => 332,  751 => 331,  748 => 330,  745 => 329,  739 => 325,  732 => 321,  729 => 320,  727 => 319,  724 => 318,  719 => 315,  713 => 313,  710 => 312,  704 => 310,  701 => 309,  695 => 307,  692 => 306,  686 => 304,  683 => 303,  677 => 301,  674 => 300,  668 => 298,  665 => 297,  659 => 295,  656 => 294,  650 => 292,  647 => 291,  641 => 289,  639 => 288,  635 => 286,  633 => 285,  629 => 284,  625 => 283,  622 => 282,  619 => 281,  613 => 277,  605 => 272,  601 => 271,  595 => 270,  592 => 269,  589 => 268,  581 => 263,  577 => 262,  571 => 261,  568 => 260,  565 => 259,  557 => 254,  553 => 253,  547 => 252,  544 => 251,  542 => 250,  537 => 248,  533 => 247,  530 => 246,  527 => 245,  524 => 244,  518 => 240,  510 => 235,  506 => 234,  500 => 233,  497 => 232,  494 => 231,  486 => 226,  482 => 225,  476 => 224,  473 => 223,  470 => 222,  462 => 217,  458 => 216,  452 => 215,  449 => 214,  446 => 213,  438 => 208,  434 => 207,  428 => 206,  425 => 205,  423 => 204,  419 => 203,  415 => 202,  412 => 201,  409 => 200,  407 => 199,  400 => 194,  392 => 189,  388 => 188,  382 => 187,  379 => 186,  376 => 185,  368 => 180,  364 => 179,  358 => 178,  355 => 177,  352 => 176,  344 => 171,  340 => 170,  334 => 169,  331 => 168,  329 => 167,  325 => 165,  318 => 161,  314 => 160,  311 => 159,  309 => 158,  305 => 157,  301 => 156,  298 => 155,  290 => 150,  286 => 149,  282 => 148,  279 => 147,  276 => 146,  273 => 145,  267 => 141,  259 => 136,  255 => 135,  249 => 134,  246 => 133,  243 => 132,  235 => 127,  231 => 126,  225 => 125,  222 => 124,  219 => 123,  211 => 118,  207 => 117,  201 => 116,  198 => 115,  196 => 114,  192 => 113,  188 => 112,  185 => 111,  182 => 110,  179 => 109,  171 => 104,  167 => 103,  163 => 102,  160 => 101,  157 => 100,  149 => 95,  145 => 94,  141 => 93,  138 => 92,  135 => 91,  127 => 86,  123 => 85,  119 => 84,  113 => 83,  110 => 82,  108 => 81,  103 => 78,  97 => 76,  94 => 75,  88 => 73,  86 => 72,  82 => 71,  76 => 70,  71 => 68,  68 => 67,  60 => 62,  56 => 61,  49 => 59,  46 => 58,  43 => 57,);
    }

    /** @deprecated since 1.27 (to be removed in 2.0). Use getSourceContext() instead */
    public function getSource()
    {
        @trigger_error('The '.__METHOD__.' method is deprecated since version 1.27 and will be removed in 2.0. Use getSourceContext() instead.', E_USER_DEPRECATED);

        return $this->getSourceContext()->getCode();
    }

    public function getSourceContext()
    {
        return new Twig_Source("", "sites/all/themes/d8w3css/templates/layout/page.html.twig", "C:\\Users\\Javi\\Dropbox\\UGR\\4\\2_Cuatrimestre\\Sistemas_Cooperativos_y_Gestion_de_Contenidos\\drupal\\sites\\all\\themes\\d8w3css\\templates\\layout\\page.html.twig");
    }
}
