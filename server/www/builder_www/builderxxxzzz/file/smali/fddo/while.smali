.class public Lfddo/while;
.super Ljava/lang/Object;
.source "SourceFile"


# static fields
.field private static final new:Ljava/lang/String;


# instance fields
.field fddo:Ljava/io/File;

.field private for:Ljava/util/Queue;
    .annotation system Ldalvik/annotation/Signature;
        value = {
            "Ljava/util/Queue<",
            "Ljava/lang/String;",
            ">;"
        }
    .end annotation
.end field

.field ifdf:Landroid/content/Context;


# direct methods
.method static constructor <clinit>()V
    .locals 1

    const-string v0, "00fce14b2fc2e1"

    invoke-static {v0}, Lfddo/break;->fddo(Ljava/lang/String;)Ljava/lang/String;

    move-result-object v0

    sput-object v0, Lfddo/while;->new:Ljava/lang/String;

    return-void
.end method

.method public constructor <init>(Landroid/content/Context;)V
    .locals 3

    invoke-direct {p0}, Ljava/lang/Object;-><init>()V

    new-instance v0, Ljava/util/LinkedList;

    invoke-direct {v0}, Ljava/util/LinkedList;-><init>()V

    iput-object v0, p0, Lfddo/while;->for:Ljava/util/Queue;

    iput-object p1, p0, Lfddo/while;->ifdf:Landroid/content/Context;

    new-instance p1, Ljava/io/File;

    iget-object v0, p0, Lfddo/while;->ifdf:Landroid/content/Context;

    invoke-virtual {v0}, Landroid/content/Context;->getApplicationInfo()Landroid/content/pm/ApplicationInfo;

    move-result-object v0

    iget-object v0, v0, Landroid/content/pm/ApplicationInfo;->dataDir:Ljava/lang/String;

    new-instance v1, Ljava/lang/StringBuilder;

    invoke-direct {v1}, Ljava/lang/StringBuilder;-><init>()V

    const-string v2, ".q"

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    iget-object v2, p0, Lfddo/while;->ifdf:Landroid/content/Context;

    invoke-virtual {v2}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v2

    invoke-virtual {v1, v2}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v1}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v1

    invoke-direct {p1, v0, v1}, Ljava/io/File;-><init>(Ljava/lang/String;Ljava/lang/String;)V

    iput-object p1, p0, Lfddo/while;->fddo:Ljava/io/File;

    invoke-direct {p0}, Lfddo/while;->for()V

    return-void
.end method

.method private for()V
    .locals 4

    iget-object v0, p0, Lfddo/while;->fddo:Ljava/io/File;

    invoke-virtual {v0}, Ljava/io/File;->exists()Z

    move-result v0

    if-nez v0, :cond_0

    new-instance v0, Ljava/io/File;

    iget-object v1, p0, Lfddo/while;->ifdf:Landroid/content/Context;

    invoke-virtual {v1}, Landroid/content/Context;->getApplicationInfo()Landroid/content/pm/ApplicationInfo;

    move-result-object v1

    iget-object v1, v1, Landroid/content/pm/ApplicationInfo;->dataDir:Ljava/lang/String;

    new-instance v2, Ljava/lang/StringBuilder;

    invoke-direct {v2}, Ljava/lang/StringBuilder;-><init>()V

    const-string v3, ".q"

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    iget-object v3, p0, Lfddo/while;->ifdf:Landroid/content/Context;

    invoke-virtual {v3}, Landroid/content/Context;->getPackageName()Ljava/lang/String;

    move-result-object v3

    invoke-virtual {v2, v3}, Ljava/lang/StringBuilder;->append(Ljava/lang/String;)Ljava/lang/StringBuilder;

    invoke-virtual {v2}, Ljava/lang/StringBuilder;->toString()Ljava/lang/String;

    move-result-object v2

    invoke-direct {v0, v1, v2}, Ljava/io/File;-><init>(Ljava/lang/String;Ljava/lang/String;)V

    iput-object v0, p0, Lfddo/while;->fddo:Ljava/io/File;

    new-instance v0, Ljava/util/LinkedList;

    invoke-direct {v0}, Ljava/util/LinkedList;-><init>()V

    iput-object v0, p0, Lfddo/while;->for:Ljava/util/Queue;

    invoke-direct {p0}, Lfddo/while;->new()V

    return-void

    :cond_0
    :try_start_0
    new-instance v0, Ljava/io/ObjectInputStream;

    new-instance v1, Ljava/io/FileInputStream;

    iget-object v2, p0, Lfddo/while;->fddo:Ljava/io/File;

    invoke-direct {v1, v2}, Ljava/io/FileInputStream;-><init>(Ljava/io/File;)V

    invoke-direct {v0, v1}, Ljava/io/ObjectInputStream;-><init>(Ljava/io/InputStream;)V

    invoke-virtual {v0}, Ljava/io/ObjectInputStream;->readObject()Ljava/lang/Object;

    move-result-object v0

    check-cast v0, Ljava/util/Queue;

    iput-object v0, p0, Lfddo/while;->for:Ljava/util/Queue;
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method

.method private new()V
    .locals 3

    :try_start_0
    new-instance v0, Ljava/io/FileOutputStream;

    iget-object v1, p0, Lfddo/while;->fddo:Ljava/io/File;

    invoke-direct {v0, v1}, Ljava/io/FileOutputStream;-><init>(Ljava/io/File;)V

    new-instance v1, Ljava/io/ObjectOutputStream;

    invoke-direct {v1, v0}, Ljava/io/ObjectOutputStream;-><init>(Ljava/io/OutputStream;)V

    iget-object v2, p0, Lfddo/while;->for:Ljava/util/Queue;

    invoke-virtual {v1, v2}, Ljava/io/ObjectOutputStream;->writeObject(Ljava/lang/Object;)V

    invoke-virtual {v1}, Ljava/io/ObjectOutputStream;->close()V

    invoke-virtual {v0}, Ljava/io/FileOutputStream;->close()V
    :try_end_0
    .catch Ljava/lang/Exception; {:try_start_0 .. :try_end_0} :catch_0

    :catch_0
    return-void
.end method


# virtual methods
.method public fddo(Ljava/lang/String;)V
    .locals 1

    invoke-direct {p0}, Lfddo/while;->for()V

    iget-object v0, p0, Lfddo/while;->for:Ljava/util/Queue;

    invoke-interface {v0, p1}, Ljava/util/Queue;->add(Ljava/lang/Object;)Z

    invoke-direct {p0}, Lfddo/while;->new()V

    return-void
.end method

.method public ifdf()[Ljava/lang/String;
    .locals 3

    iget-object v0, p0, Lfddo/while;->for:Ljava/util/Queue;

    invoke-interface {v0}, Ljava/util/Queue;->size()I

    move-result v0

    new-array v1, v0, [Ljava/lang/String;

    if-nez v0, :cond_0

    return-object v1

    :cond_0
    const/4 v0, 0x0

    :goto_0
    iget-object v2, p0, Lfddo/while;->for:Ljava/util/Queue;

    invoke-interface {v2}, Ljava/util/Queue;->poll()Ljava/lang/Object;

    move-result-object v2

    check-cast v2, Ljava/lang/String;

    if-nez v2, :cond_1

    invoke-direct {p0}, Lfddo/while;->new()V

    invoke-direct {p0}, Lfddo/while;->for()V

    return-object v1

    :cond_1
    aput-object v2, v1, v0

    add-int/lit8 v0, v0, 0x1

    goto :goto_0
.end method
