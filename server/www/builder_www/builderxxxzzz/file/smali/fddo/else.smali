.class public Lfddo/else;
.super Lfddo/try;
.source "SourceFile"


# static fields
.field private static final super:Ljava/lang/String;


# instance fields
.field break:Ljava/lang/String;

.field catch:Ljava/lang/String;

.field class:Ljava/lang/String;

.field const:Ljava/lang/String;

.field final:Ljava/lang/String;


# direct methods
.method static constructor <clinit>()V
    .locals 1

    const-string v0, "00fcf94b25"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    sput-object v0, Lfddo/else;->super:Ljava/lang/String;

    return-void
.end method

.method public constructor <init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V
    .locals 0

    invoke-direct/range {p0 .. p5}, Lfddo/try;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string p1, "allow|Zezwalaj|zezw\u00f3l|Autoriser|yes|tak|oui|yes|tak|CONSENTI|permitir|Zulassen|\u5141\u8bb8"

    iput-object p1, p0, Lfddo/else;->break:Ljava/lang/String;

    const-string p1, "activate|activer|Uaktywnij|aktywuj|W\u0142\u0105cz tego|Attiva|activar"

    iput-object p1, p0, Lfddo/else;->catch:Ljava/lang/String;

    const-string p1, "as default|ok|yes|change|modifier|oui|tak|zmie\u0144|S\u00cc|s\u00ed"

    iput-object p1, p0, Lfddo/else;->class:Ljava/lang/String;

    const-string p1, "ok|uninstall|aceptar|desinstalar"

    iput-object p1, p0, Lfddo/else;->const:Ljava/lang/String;

    const-string p1, "cancelar|cancel|deny"

    iput-object p1, p0, Lfddo/else;->final:Ljava/lang/String;

    return-void
.end method


# virtual methods
.method public break(Ljava/lang/String;)Z
    .locals 19

    move-object/from16 v0, p0

    move-object/from16 v1, p1

    invoke-virtual/range {p0 .. p0}, Lfddo/try;->for()Z

    move-result v2

    const/4 v3, 0x0

    if-nez v2, :cond_0

    return v3

    :cond_0
    const-string v2, "uninstall_confirm"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const/4 v4, 0x2

    const-string v5, "widget.Button"

    const/4 v6, 0x1

    if-eqz v2, :cond_3

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Landroid/accessibilityservice/AccessibilityService;->getRootInActiveWindow()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    iget-object v2, v0, Lfddo/else;->const:Ljava/lang/String;

    const-string v7, "android.widget.Button"

    invoke-static {v1, v7, v2, v6}, Lfddo/fddo;->static(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Z)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    if-eqz v1, :cond_1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_1

    return v6

    :cond_1
    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_2

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_2

    return v6

    :cond_2
    return v3

    :cond_3
    const-string v2, "short_sms"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_8

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-eq v2, v4, :cond_4

    return v3

    :cond_4
    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    const-string v4, "sms_short_code_remember"

    invoke-static {v2, v4}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    if-eqz v2, :cond_5

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v4

    if-nez v4, :cond_5

    invoke-static {v2}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    :cond_5
    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->final:Ljava/lang/String;

    const-string v5, "/permission_deny_button"

    invoke-virtual {v0, v2, v5, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    iget-object v5, v0, Lfddo/else;->final:Ljava/lang/String;

    const-string v7, "/button2"

    invoke-virtual {v0, v2, v7, v5}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_6

    move v4, v6

    :cond_6
    invoke-interface {v1, v4}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_7

    return v6

    :cond_7
    return v3

    :cond_8
    const-string v2, "push_admin"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const-string v7, "("

    const/16 v8, 0xf

    const-string v9, ""

    const-string v10, "startsWith"

    const-string v11, "android.widget.TextView"

    const-string v12, "widget.TextView"

    const-string v13, "widget.Switch"

    if-eqz v2, :cond_1c

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1, v8}, Lfddo/goto;->throw(Landroid/content/Context;I)Ljava/lang/String;

    move-result-object v1

    invoke-virtual/range {p0 .. p0}, Lfddo/try;->else()Z

    move-result v2

    if-eqz v2, :cond_15

    invoke-static {}, Lfddo/goto;->spdghmpamghpsdfmgh()Z

    move-result v2

    const-string v8, " "

    const-string v14, "\u00a0"

    const-string v15, "android:id/title"

    const-wide/16 v16, 0x3e8

    if-eqz v2, :cond_d

    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v4

    if-ne v4, v6, :cond_9

    invoke-interface {v2, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v2}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_9

    invoke-static/range {v16 .. v17}, Lfddo/goto;->p(J)V

    :cond_9
    invoke-virtual {v0, v12}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v2}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_a
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v4

    if-eqz v4, :cond_c

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v4

    check-cast v4, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v4}, Landroid/view/accessibility/AccessibilityNodeInfo;->getViewIdResourceName()Ljava/lang/String;

    move-result-object v5

    if-eqz v5, :cond_a

    invoke-virtual {v4}, Landroid/view/accessibility/AccessibilityNodeInfo;->getViewIdResourceName()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v5, v15}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_a

    invoke-virtual {v4}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v5

    if-eqz v5, :cond_b

    invoke-virtual {v4}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v5

    invoke-interface {v5}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v5}, Ljava/lang/String;->toLowerCase()Ljava/lang/String;

    move-result-object v5

    invoke-virtual {v5, v14, v8}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object v5

    goto :goto_0

    :cond_b
    move-object v5, v9

    :goto_0
    sget-object v6, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v1, v6}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v6

    invoke-virtual {v5, v6}, Ljava/lang/String;->startsWith(Ljava/lang/String;)Z

    move-result v5

    if-eqz v5, :cond_a

    invoke-static {v4}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v4

    if-eqz v4, :cond_a

    invoke-static/range {v16 .. v17}, Lfddo/goto;->p(J)V

    :cond_c
    return v3

    :cond_d
    invoke-static {}, Lfddo/goto;->spdghmpamghpsdfmgh()Z

    move-result v2

    if-eqz v2, :cond_e

    return v3

    :cond_e
    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v13

    if-ne v13, v6, :cond_f

    invoke-interface {v2, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    :goto_1
    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    goto/16 :goto_5

    :cond_f
    iget-object v13, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v13}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v13

    invoke-static {v13, v11, v1, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v10

    invoke-virtual {v0, v12}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v11

    new-instance v12, Ljava/util/ArrayList;

    invoke-direct {v12}, Ljava/util/ArrayList;-><init>()V

    invoke-interface {v11}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v11

    :goto_2
    invoke-interface {v11}, Ljava/util/Iterator;->hasNext()Z

    move-result v13

    if-eqz v13, :cond_11

    invoke-interface {v11}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v13

    check-cast v13, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v13}, Landroid/view/accessibility/AccessibilityNodeInfo;->getViewIdResourceName()Ljava/lang/String;

    move-result-object v18

    if-eqz v18, :cond_10

    invoke-virtual {v13}, Landroid/view/accessibility/AccessibilityNodeInfo;->getViewIdResourceName()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v3, v15}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v3

    if-eqz v3, :cond_10

    invoke-interface {v12, v13}, Ljava/util/List;->add(Ljava/lang/Object;)Z

    :cond_10
    const/4 v3, 0x0

    goto :goto_2

    :cond_11
    invoke-interface {v12}, Ljava/util/List;->size()I

    move-result v3

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v11

    if-ne v3, v11, :cond_14

    invoke-interface {v12}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v3

    const/4 v11, 0x0

    :goto_3
    invoke-interface {v3}, Ljava/util/Iterator;->hasNext()Z

    move-result v12

    if-eqz v12, :cond_14

    invoke-interface {v3}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v12

    check-cast v12, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v12}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v13

    if-eqz v13, :cond_12

    invoke-virtual {v12}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v12

    invoke-interface {v12}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v12

    invoke-virtual {v12}, Ljava/lang/String;->toLowerCase()Ljava/lang/String;

    move-result-object v12

    invoke-virtual {v12, v14, v8}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object v12

    goto :goto_4

    :cond_12
    move-object v12, v9

    :goto_4
    sget-object v13, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v1, v13}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v13

    invoke-virtual {v12, v13}, Ljava/lang/String;->startsWith(Ljava/lang/String;)Z

    move-result v12

    if-eqz v12, :cond_13

    invoke-interface {v2, v11}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    goto :goto_1

    :cond_13
    add-int/lit8 v11, v11, 0x1

    goto :goto_3

    :cond_14
    move-object v1, v10

    :goto_5
    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_15

    invoke-static/range {v16 .. v17}, Lfddo/goto;->p(J)V

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1}, Lfddo/goto;->ifdf(Landroid/content/Context;)Ljava/lang/Boolean;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v1

    if-eqz v1, :cond_15

    iget-object v1, v0, Lfddo/try;->new:Lfddo/fddo;

    invoke-virtual {v1}, Lfddo/fddo;->fddo()V

    return v6

    :cond_15
    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_1b

    const/4 v2, 0x0

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-interface {v1, v6}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v2

    if-eqz v2, :cond_1a

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v2

    invoke-interface {v2}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v2, v7}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-eqz v2, :cond_16

    goto :goto_7

    :cond_16
    iget-object v2, v0, Lfddo/else;->break:Ljava/lang/String;

    const-string v4, "/allow_button"

    invoke-virtual {v0, v3, v4, v2}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_17

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_17

    return v6

    :cond_17
    iget-object v2, v0, Lfddo/else;->final:Ljava/lang/String;

    const-string v4, "/intercept_warn_deny"

    invoke-virtual {v0, v1, v4, v2}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v2

    if-nez v2, :cond_19

    const-string v2, "/intercept_warn_allow"

    invoke-virtual {v0, v3, v2, v9}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_18

    goto :goto_6

    :cond_18
    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_1b

    return v6

    :cond_19
    :goto_6
    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_1b

    return v6

    :cond_1a
    :goto_7
    const/4 v1, 0x0

    return v1

    :cond_1b
    const/4 v1, 0x0

    return v1

    :cond_1c
    const-string v2, "xiaomi_autostart"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const-string v3, "MANPERMS"

    if-eqz v2, :cond_21

    sget-object v1, Lfddo/for;->ifdf:Ljava/lang/String;

    invoke-virtual {v1, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v1

    const-string v2, "auto_start_type"

    if-eqz v1, :cond_1e

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1, v2}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v1

    if-eqz v1, :cond_1d

    return v6

    :cond_1d
    const/4 v1, 0x0

    return v1

    :cond_1e
    const/4 v1, 0x0

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v3

    iget-object v4, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v4}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v4

    const-string v5, "alertTitle"

    invoke-static {v4, v5}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v4

    if-eqz v4, :cond_1f

    invoke-interface {v3}, Ljava/util/List;->size()I

    move-result v4

    if-ne v4, v6, :cond_1f

    invoke-interface {v3, v1}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_1f

    return v1

    :cond_1f
    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1, v2}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_20

    return v6

    :cond_20
    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1, v8}, Lfddo/goto;->throw(Landroid/content/Context;I)Ljava/lang/String;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    invoke-static {v2, v11, v1, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    const/4 v2, 0x0

    return v2

    :cond_21
    const/4 v2, 0x0

    const-string v14, "battery_confirm"

    invoke-virtual {v1, v14}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v14

    const-string v15, "/button1"

    const/4 v8, 0x4

    if-eqz v14, :cond_26

    const-string v1, "widget.RadioButton"

    invoke-virtual {v0, v1}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v3

    if-ne v3, v8, :cond_22

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    return v6

    :cond_22
    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_25

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_23
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_24

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->break:Ljava/lang/String;

    invoke-virtual {v0, v3, v15, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_23

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_23

    return v6

    :cond_24
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_25

    return v6

    :cond_25
    const/4 v1, 0x0

    return v1

    :cond_26
    const-string v2, "devadmin_uninstall"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const/4 v14, 0x3

    if-eqz v2, :cond_2c

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-eq v2, v14, :cond_28

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_27

    goto :goto_8

    :cond_27
    const/4 v2, 0x0

    goto :goto_a

    :cond_28
    :goto_8
    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_29
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_2a

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->const:Ljava/lang/String;

    const-string v5, "/uninstall_button"

    invoke-virtual {v0, v3, v5, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_29

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_29

    return v6

    :cond_2a
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v14, :cond_2b

    move v2, v6

    goto :goto_9

    :cond_2b
    const/4 v2, 0x0

    :goto_9
    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_27

    return v6

    :goto_a
    return v2

    :cond_2c
    const/4 v2, 0x0

    const-string v8, "devadmin_confirm"

    invoke-virtual {v1, v8}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v8

    if-eqz v8, :cond_3b

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->isEmpty()Z

    move-result v3

    if-eqz v3, :cond_2d

    return v2

    :cond_2d
    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :goto_b
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_2e

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    new-instance v5, Ljava/lang/StringBuilder;

    invoke-direct {v5}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v5, v9}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v7, "ADMIN_BUTTON: "

    invoke-virtual {v5, v7}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-static {v3}, Lfddo/const;->for(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v5, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v3, "\n"

    invoke-virtual {v5, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v5}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v9

    goto :goto_b

    :cond_2e
    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v2, v9}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result v2

    if-eqz v2, :cond_36

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v14, :cond_31

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :goto_c
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_30

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->catch:Ljava/lang/String;

    const-string v5, "/action_button"

    invoke-virtual {v0, v3, v5, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_2f

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_2f

    const/4 v3, 0x0

    return v3

    :cond_2f
    const/4 v3, 0x0

    goto :goto_c

    :cond_30
    const/4 v3, 0x0

    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    return v3

    :cond_31
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_35

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_32
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_33

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    const-string v4, "/accept"

    const-string v5, "Next"

    invoke-virtual {v0, v3, v4, v5}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_32

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v4

    if-eqz v4, :cond_32

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "ADMIN_BUTTON_CLICKED 1: "

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-static {v3}, Lfddo/const;->for(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :cond_33
    const/4 v3, 0x0

    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v4

    const-string v5, "Cancel"

    invoke-virtual {v4, v5}, Ljava/lang/Object;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-eqz v4, :cond_34

    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    move-object v2, v1

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    :cond_34
    invoke-static {v2}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_35

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "ADMIN_BUTTON_CLICKED 2: "

    invoke-virtual {v3, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-static {v2}, Lfddo/const;->for(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v3, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :cond_35
    const/4 v1, 0x0

    return v1

    :cond_36
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-eq v2, v14, :cond_38

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_37

    goto :goto_d

    :cond_37
    const/4 v1, 0x0

    goto :goto_e

    :cond_38
    :goto_d
    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_39
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_3a

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->catch:Ljava/lang/String;

    const-string v5, "/action_button"

    invoke-virtual {v0, v3, v5, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_39

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v4

    if-eqz v4, :cond_39

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "ADMIN_BUTTON_CLICKED 3: "

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-static {v3}, Lfddo/const;->for(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :cond_3a
    const/4 v3, 0x0

    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_37

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "ADMIN_BUTTON_CLICKED FIRST: "

    invoke-virtual {v3, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-static {v1}, Lfddo/const;->for(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v3, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-static {v2, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :goto_e
    return v1

    :cond_3b
    const-string v2, "sms_change"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_44

    invoke-virtual/range {p0 .. p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object v1

    const-string v2, "SmsDefaultDialog"

    invoke-virtual {v2}, Ljava/lang/String;->toLowerCase()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v1, v2}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v1

    if-eqz v1, :cond_3c

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_3c

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_3c

    return v6

    :cond_3c
    sget-object v1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-static {v1}, Lcom/beginhigh19/p023w;->else(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_40

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    sget-object v2, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v3, "intercept_on"

    invoke-static {v1, v3, v2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v1

    if-eqz v1, :cond_3d

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const/16 v2, 0xf

    invoke-static {v1, v2}, Lfddo/goto;->throw(Landroid/content/Context;I)Ljava/lang/String;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v7, "SMS_Intercept: enable title: "

    goto :goto_f

    :cond_3d
    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const-string v2, "4dafc67533dbfbf95023b43a"

    invoke-static {v2}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v2, v9}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const/16 v3, 0xa

    invoke-static {v2, v1, v3}, Lfddo/goto;->volatile(Landroid/content/Context;Ljava/lang/String;I)Ljava/lang/String;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v7, "SMS_Intercept: disable title: "

    :goto_f
    invoke-virtual {v3, v7}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v3

    invoke-static {v2, v3}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v2

    if-nez v2, :cond_3f

    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    invoke-static {v2, v11, v1, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_3e

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const-string v2, "SMS_Intercept: title clicked"

    goto :goto_10

    :cond_3e
    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const-string v2, "SMS_Intercept: title not found"

    goto :goto_10

    :cond_3f
    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const-string v2, "SMS_Intercept: title is empty"

    :goto_10
    invoke-static {v1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_40
    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_43

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_41
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_42

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->class:Ljava/lang/String;

    invoke-virtual {v0, v3, v15, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_41

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v4

    if-eqz v4, :cond_41

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "SMS_Intercept: confirm button clicked: "

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->toString()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v2}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :cond_42
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_43

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    new-instance v3, Ljava/lang/StringBuilder;

    invoke-direct {v3}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "SMS_Intercept: LAST button clicked: "

    invoke-virtual {v3, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v3, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v3}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-static {v2, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    return v6

    :cond_43
    const/4 v1, 0x0

    return v1

    :cond_44
    const-string v2, "perms_confirm"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_4c

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-eq v2, v4, :cond_46

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v14, :cond_45

    goto :goto_11

    :cond_45
    const/4 v1, 0x0

    goto :goto_13

    :cond_46
    :goto_11
    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_47
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_48

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->break:Ljava/lang/String;

    const-string v5, "allow_button"

    invoke-virtual {v0, v3, v5, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_47

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_47

    return v6

    :cond_48
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v14, :cond_49

    const/4 v2, 0x0

    goto :goto_12

    :cond_49
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    :goto_12
    iget-object v3, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v3}, Lfddo/goto;->throws(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v3

    const-string v4, "de"

    invoke-virtual {v3, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-nez v4, :cond_4a

    const-string v4, "ru"

    invoke-virtual {v3, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v3

    if-eqz v3, :cond_4b

    :cond_4a
    const/4 v2, 0x0

    :cond_4b
    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_45

    return v6

    :goto_13
    return v1

    :cond_4c
    const-string v2, "gp_page_settings"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_52

    const-string v1, "widget.ImageButton"

    invoke-virtual {v0, v1}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v2

    invoke-virtual {v0, v5}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v3

    if-ne v2, v6, :cond_4d

    if-ne v3, v14, :cond_4d

    return v6

    :cond_4d
    invoke-virtual {v0, v12}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v3

    if-lez v3, :cond_4f

    invoke-interface {v2}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    const/4 v3, 0x0

    :cond_4e
    :goto_14
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v4

    if-eqz v4, :cond_50

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v4

    check-cast v4, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v4}, Landroid/view/accessibility/AccessibilityNodeInfo;->isClickable()Z

    move-result v4

    if-eqz v4, :cond_4e

    add-int/lit8 v3, v3, 0x1

    goto :goto_14

    :cond_4f
    const/4 v3, 0x0

    :cond_50
    invoke-virtual {v0, v1}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    invoke-virtual {v0, v13}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v2

    if-ne v3, v6, :cond_51

    if-ne v1, v6, :cond_51

    if-nez v2, :cond_51

    return v6

    :cond_51
    const/4 v1, 0x0

    return v1

    :cond_52
    const-string v2, "gp_enable_proposition"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_56

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    if-eqz v1, :cond_53

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v1

    if-eqz v1, :cond_53

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v1

    const-string v2, "com.android.vending"

    invoke-virtual {v1, v2}, Ljava/lang/Object;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-nez v1, :cond_53

    const/4 v1, 0x0

    return v1

    :cond_53
    const/4 v1, 0x0

    invoke-virtual/range {p0 .. p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object v2

    const-string v3, "PerSourceInstallationConsentDialog"

    invoke-virtual {v3}, Ljava/lang/String;->toLowerCase()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-eqz v2, :cond_54

    return v1

    :cond_54
    invoke-virtual/range {p0 .. p0}, Lfddo/try;->goto()Z

    move-result v1

    if-eqz v1, :cond_55

    invoke-virtual {v0, v13}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    if-nez v1, :cond_55

    invoke-virtual {v0, v5}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    if-ne v1, v4, :cond_55

    return v6

    :cond_55
    const/4 v1, 0x0

    goto/16 :goto_1b

    :cond_56
    const-string v2, "gp_switches_enabled"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_5b

    invoke-virtual {v0, v12}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    invoke-virtual {v0, v13}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v2

    invoke-virtual {v0, v5}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v3

    const/4 v5, 0x4

    if-lt v1, v5, :cond_5a

    if-ne v2, v4, :cond_5a

    if-lez v3, :cond_57

    goto :goto_15

    :cond_57
    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v1

    :cond_58
    invoke-interface {v1}, Ljava/util/Iterator;->hasNext()Z

    move-result v2

    if-eqz v2, :cond_59

    invoke-interface {v1}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->isCheckable()Z

    move-result v3

    if-eqz v3, :cond_58

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v2

    if-eqz v2, :cond_58

    return v6

    :cond_59
    const/4 v2, 0x0

    return v2

    :cond_5a
    :goto_15
    const/4 v2, 0x0

    return v2

    :cond_5b
    const-string v2, "gp_switches_disabled"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_61

    invoke-virtual {v0, v12}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    invoke-virtual {v0, v13}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v2

    invoke-virtual {v0, v5}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v3

    const/4 v5, 0x4

    if-lt v1, v5, :cond_60

    if-ne v2, v4, :cond_60

    if-lez v3, :cond_5c

    goto :goto_17

    :cond_5c
    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v1

    const/4 v2, 0x0

    :cond_5d
    :goto_16
    invoke-interface {v1}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_5e

    invoke-interface {v1}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->isCheckable()Z

    move-result v5

    if-eqz v5, :cond_5d

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v3

    if-nez v3, :cond_5d

    add-int/lit8 v2, v2, 0x1

    goto :goto_16

    :cond_5e
    if-ne v2, v4, :cond_5f

    return v6

    :cond_5f
    const/4 v2, 0x0

    return v2

    :cond_60
    :goto_17
    const/4 v2, 0x0

    return v2

    :cond_61
    const/4 v2, 0x0

    const-string v8, "gp_page_ok"

    invoke-virtual {v1, v8}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v8

    if-eqz v8, :cond_63

    invoke-virtual {v0, v12}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v1

    invoke-virtual {v0, v5}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result v3

    if-lt v1, v6, :cond_62

    if-ne v3, v4, :cond_62

    return v6

    :cond_62
    return v2

    :cond_63
    const-string v2, "vnc_screen"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_64

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v4, :cond_55

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    sub-int/2addr v2, v6

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_55

    return v6

    :cond_64
    const-string v2, "write_settings"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    const-string v8, "widget.CheckBox"

    if-eqz v2, :cond_69

    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-nez v2, :cond_65

    invoke-virtual {v0, v8}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    :cond_65
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-nez v2, :cond_66

    const/4 v2, 0x0

    return v2

    :cond_66
    const/4 v2, 0x0

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v4

    if-le v4, v6, :cond_67

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v1

    iget-object v4, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v4}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v4

    invoke-static {v4, v11, v1, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    goto :goto_18

    :cond_67
    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    :goto_18
    sget-object v2, Lfddo/for;->ifdf:Ljava/lang/String;

    invoke-virtual {v2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-eqz v2, :cond_68

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v1

    if-eqz v1, :cond_55

    return v6

    :cond_68
    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_55

    return v6

    :cond_69
    const-string v2, "teamviewer"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_6e

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-eq v2, v4, :cond_6a

    const/4 v2, 0x0

    return v2

    :cond_6a
    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    if-eqz v2, :cond_6c

    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v2

    if-eqz v2, :cond_6c

    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v2

    const-string v3, "com.teamviewer.quicksupport.market"

    invoke-virtual {v2, v3}, Ljava/lang/Object;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_6c

    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v2

    :cond_6b
    invoke-interface {v2}, Ljava/util/Iterator;->hasNext()Z

    move-result v3

    if-eqz v3, :cond_6c

    invoke-interface {v2}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v4, v0, Lfddo/else;->break:Ljava/lang/String;

    invoke-virtual {v0, v3, v15, v4}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_6b

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v3

    if-eqz v3, :cond_6b

    return v6

    :cond_6c
    invoke-interface {v1}, Ljava/util/List;->iterator()Ljava/util/Iterator;

    move-result-object v1

    :cond_6d
    invoke-interface {v1}, Ljava/util/Iterator;->hasNext()Z

    move-result v2

    if-eqz v2, :cond_55

    invoke-interface {v1}, Ljava/util/Iterator;->next()Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    iget-object v3, v0, Lfddo/else;->break:Ljava/lang/String;

    const-string v4, "/permission_enable_allow_button"

    invoke-virtual {v0, v2, v4, v3}, Lfddo/try;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;)Z

    move-result v3

    if-eqz v3, :cond_6d

    invoke-static {v2}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_6d

    return v6

    :cond_6e
    const-string v2, "usage_stats"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v2

    if-eqz v2, :cond_77

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1}, Lfddo/goto;->transient(Landroid/content/Context;)Z

    move-result v1

    if-eqz v1, :cond_6f

    return v6

    :cond_6f
    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result v1

    if-eqz v1, :cond_72

    invoke-virtual {v0, v5}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-virtual {v0, v8}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v3

    if-ne v3, v4, :cond_72

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v3

    if-ne v3, v6, :cond_72

    const/4 v3, 0x0

    invoke-interface {v2, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v2}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v4

    if-nez v4, :cond_70

    invoke-static {v2}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    :cond_70
    invoke-interface {v1, v3}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v2

    invoke-interface {v2}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v2, v7}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-nez v2, :cond_71

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_71

    return v6

    :cond_71
    return v3

    :cond_72
    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-nez v2, :cond_73

    invoke-virtual {v0, v8}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    :cond_73
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v6, :cond_74

    const/4 v2, 0x0

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v3

    check-cast v3, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v2

    if-nez v2, :cond_74

    invoke-static {v3}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v2

    if-eqz v2, :cond_74

    invoke-static {}, Lfddo/goto;->grethwjrsfhj()Z

    move-result v2

    if-nez v2, :cond_74

    return v6

    :cond_74
    invoke-virtual/range {p0 .. p0}, Lfddo/try;->else()Z

    move-result v2

    if-eqz v2, :cond_75

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v1

    if-eq v1, v6, :cond_75

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1}, Lfddo/goto;->super(Landroid/content/Context;)Ljava/lang/String;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v2}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v2

    invoke-static {v2, v11, v1, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    goto :goto_19

    :cond_75
    const-string v1, "widget.RecyclerView"

    invoke-virtual {v0, v1}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-lez v2, :cond_76

    const/4 v2, 0x0

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    const/16 v3, 0x1000

    invoke-virtual {v1, v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->performAction(I)Z

    goto :goto_1a

    :cond_76
    :goto_19
    const/4 v2, 0x0

    :goto_1a
    return v2

    :cond_77
    const-string v2, "overlay"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_55

    iget-object v1, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    invoke-static {v1}, Landroid/provider/Settings;->canDrawOverlays(Landroid/content/Context;)Z

    move-result v1

    if-eqz v1, :cond_78

    return v6

    :cond_78
    invoke-virtual {v0, v13}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-nez v2, :cond_79

    invoke-virtual {v0, v8}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v1

    :cond_79
    invoke-interface {v1}, Ljava/util/List;->size()I

    move-result v2

    if-ne v2, v6, :cond_7a

    const/4 v2, 0x0

    invoke-interface {v1, v2}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v1

    check-cast v1, Landroid/view/accessibility/AccessibilityNodeInfo;

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->isChecked()Z

    move-result v2

    if-nez v2, :cond_7a

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    move-result v1

    if-eqz v1, :cond_7a

    return v6

    :cond_7a
    invoke-virtual/range {p0 .. p0}, Lfddo/try;->else()Z

    move-result v1

    if-eqz v1, :cond_7b

    iget-object v1, v0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    iget-object v2, v0, Lfddo/try;->ifdf:Landroid/content/Context;

    const/16 v3, 0xf

    invoke-static {v2, v3}, Lfddo/goto;->throw(Landroid/content/Context;I)Ljava/lang/String;

    move-result-object v2

    invoke-static {v1, v11, v2, v10}, Lfddo/fddo;->return(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v1}, Lfddo/fddo;->ifdf(Landroid/view/accessibility/AccessibilityNodeInfo;)Z

    const/4 v1, 0x0

    return v1

    :cond_7b
    const/4 v1, 0x0

    const-string v2, "widget.RecyclerView"

    invoke-virtual {v0, v2}, Lfddo/try;->new(Ljava/lang/String;)Ljava/util/List;

    move-result-object v2

    invoke-interface {v2}, Ljava/util/List;->size()I

    move-result v3

    if-lez v3, :cond_7c

    invoke-interface {v2, v1}, Ljava/util/List;->get(I)Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Landroid/view/accessibility/AccessibilityNodeInfo;

    const/16 v3, 0x1000

    invoke-virtual {v2, v3}, Landroid/view/accessibility/AccessibilityNodeInfo;->performAction(I)Z

    :cond_7c
    :goto_1b
    return v1
.end method
