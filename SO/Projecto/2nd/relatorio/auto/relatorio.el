(TeX-add-style-hook
 "relatorio"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("ulem" "normalem")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art10"
    "inputenc"
    "fontenc"
    "graphicx"
    "grffile"
    "longtable"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "amssymb"
    "capt-of"
    "hyperref")
   (LaTeX-add-labels
    "sec:org5d4b4bd"
    "sec:org602821f"
    "fig:estrutura"
    "sec:org4c5ab82"
    "sec:orgf8a1779"
    "sec:org47b48db"
    "fig:queue1"
    "fig:queue2"
    "sec:org5859cbe"
    "sec:org154afbc"
    "sec:org053cdf9"
    "sec:orgabf89f1"
    "sec:org747d66f"
    "tab:messages"
    "sec:org1ad2619"
    "sec:orgb856bcf"
    "sec:orgf777310"
    "fig:threads"
    "sec:orgf07063a"
    "fig:handshake"
    "sec:org8837ab5"
    "sec:orgb7f6e05"
    "sec:org911493c"
    "fig:protocol"
    "sec:orga06e493"
    "sec:org57526e5"
    "sec:org294ee08"
    "sec:org6b36f13"
    "sec:orgf7fe930"
    "sec:org93ceaaf"
    "sec:org14bbe7c"
    "sec:orgf09f3bc"
    "sec:org58882b8"
    "sec:org33eb065"
    "sec:orgad34d3d"
    "sec:orgffe26d3"
    "sec:org3820134"
    "sec:org24c1a02")
   (LaTeX-add-bibliographies
    "refs"))
 :latex)

